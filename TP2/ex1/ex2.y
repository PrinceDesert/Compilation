%{
	#include <ctype.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <stdbool.h>
	#include <stdarg.h>
	#include <math.h>
	#include "typesynth.h"
	int yylex(void);
	void yyerror(char const *);
	#define STACK_CAPACITY 50
	static int stack[STACK_CAPACITY];
	static size_t stack_size = 0;
	void print_stack();
	int is_same_type(size_t size_args, type_synth $1, type_synth $3, ...); /* $1 == BOOLEAN_T && $3 == BOOLEAN_T && value == BOOLEAN_T*/
%}
%union {
	int integer;
	bool boolean;
	type_synth state;
}

%token<integer> NUMBER /* le integer est relié à l'union -> integer */
%token<boolean> BOOLEAN /* le boolean est relié à l'union −> boolean */
%type<state> expr /* le state est relié au champ de l'union state */

/* associativité à gauche et priorité des opérateurs */
/* EQ = EQUALS, NEQ = NOT EQUALS priorité plus faible */
%left EQ NEQ
%left AND OR
%left '+''-'
%left '*''/''%''^'

/* lignes = axiome */
%start lignes
%%
	lignes :
		lignes error '\n'		{ stack_size = 0; yyerrok; }
		| expr error '\n'		{ stack_size = 0; yyerrok; }
		| error '\n'			{ stack_size = 0; yyerrok; }
		| lignes expr '\n'		{ printf("%d\n", stack[0]); stack_size = 0; }
		| lignes '\n'
		| expr '\n'				{ printf("%d\n", stack[0]); stack_size = 0; }
		| '\n'
	;
	
	expr :
		'(' expr ')' {
			/* on fait rien sur la pile sur les parenthèses, on remonte juste l'expression = $2 */
			$$ = $2;
		} | expr '+' expr {
			/* $1 = expr, $2 = '+', $3 = expr */
			if (is_same_type(1, $1, $3, ARITHMETIC_T)) {
				stack[stack_size - 2] += stack[stack_size - 1];
				--stack_size;
				$$ = ARITHMETIC_T;
			} else {
				yyerror("[Erreur] '+' de typage");
				$$ = ERROR_TYPE;
			}
		} | expr '-' expr {
			if (is_same_type(1, $1, $3, ARITHMETIC_T)) {
				stack[stack_size - 2] -= stack[stack_size - 1];
				--stack_size;
				$$ = ARITHMETIC_T;
			} else {
				yyerror("[Erreur] '*' de typage");
				stack[stack_size - 2] = 0;
				stack[stack_size - 1] = 0;
				stack_size -= 2;
				$$ = ERROR_TYPE;
			}
		} | expr '*' expr {
			 /* Si $1 == ERROR || $3 == ERROR pas de multiplication */
			if (is_same_type(1, $1, $3, ARITHMETIC_T)) {
				stack[stack_size - 2] *= stack[stack_size - 1];
				--stack_size;
				$$ = ARITHMETIC_T;
			} else {
				yyerror("[Erreur] '*' de typage");
				stack[stack_size - 2] = 0;
				stack[stack_size - 1] = 0;
				stack_size -= 2;
				$$ = ERROR_TYPE;
			}
		} | expr '/' expr {
			print_stack();
			printf("DIVISION : %d / %d\n", stack[stack_size - 2], stack[stack_size - 1]);
			/* $1 = expr, $2 = aucun car pas de non terminal mais un terminal '/', $3 = expr et test division par zéro */
			if (is_same_type(1, $1, $3, ARITHMETIC_T)) {
				if (stack[stack_size - 1] != 0) {
					stack[stack_size - 2] /= stack[stack_size - 1];
					--stack_size;
					$$ = ARITHMETIC_T;
				} else {
					yyerror("[Erreur] '/0' par zéro");
					fprintf(stderr, "Test condition : ($1 == ARITHMETIC_T = %d) && ($3 == ARITHMETIC_T = %d) && ($$ == ERROR_DIVISION_ZERO = %d)\n", $1 == ARITHMETIC_T, $3 == ARITHMETIC_T, $$ == ERROR_DIVISION_ZERO);
					stack[stack_size - 2] = 0;
					stack[stack_size - 1] = 0;
					stack_size -= 2;
					$$ = ERROR_DIVISION_ZERO;
				}
			} else {
				yyerror("[Erreur] '/' de typage");
				stack[stack_size - 2] = 0;
				stack[stack_size - 1] = 0;
				stack_size -= 2;
				$$ = ERROR_TYPE;
			}
			print_stack();
		} | expr '%' expr {
			printf("MODULO : %d %% %d\n", stack[stack_size - 2], stack[stack_size - 1]);
			if (is_same_type(1, $1, $3, ARITHMETIC_T)) {
				if (stack[stack_size - 1] != 0) {
					stack[stack_size - 2] %= stack[stack_size - 1];
					--stack_size;
					$$ = ARITHMETIC_T;
				} else {
					yyerror("[Erreur] '%0' par zéro");
					fprintf(stderr, "Test condition : ($1 == ARITHMETIC_T = %d) && ($3 == ARITHMETIC_T = %d) && ($$ == ERROR_DIVISION_ZERO = %d)\n", $1 == ARITHMETIC_T, $3 == ARITHMETIC_T, $$ == ERROR_DIVISION_ZERO);
					stack[stack_size - 2] = 0;
					stack[stack_size - 1] = 0;
					stack_size -= 2;
					$$ = ERROR_DIVISION_ZERO;
				}
			} else {
				yyerror("[Erreur] '%' de typage");
				stack[stack_size - 2] = 0;
				stack[stack_size - 1] = 0;
				stack_size -= 2;
				$$ = ERROR_TYPE;
			}
		} | expr '^' expr {
			if (is_same_type(1, $1, $3, ARITHMETIC_T)) {
				if (stack[stack_size - 1] != 0) {
					stack[stack_size - 2] = pow((double) stack[stack_size - 2], (double) stack[stack_size - 1]);
					--stack_size;
					$$ = ARITHMETIC_T;
				} else {
					yyerror("[Erreur] '%0' par zéro");
					fprintf(stderr, "Test condition : ($1 == ARITHMETIC_T = %d) && ($3 == ARITHMETIC_T = %d) && ($$ == ERROR_DIVISION_ZERO = %d)\n", $1 == ARITHMETIC_T, $3 == ARITHMETIC_T, $$ == ERROR_DIVISION_ZERO);
					stack[stack_size - 2] = 0;
					stack[stack_size - 1] = 0;
					stack_size -= 2;
					$$ = ERROR_DIVISION_ZERO;
				}
			} else {
				yyerror("[Erreur] '%' de typage");
				stack[stack_size - 2] = 0;
				stack[stack_size - 1] = 0;
				stack_size -= 2;
				$$ = ERROR_TYPE;
			}
		} | expr EQ expr {
			if (is_same_type(2, $1, $3, ARITHMETIC_T, BOOLEAN_T)) {
				printf("EQUALS %d == %d = %d\n", stack[stack_size - 2], stack[stack_size - 1], stack[stack_size - 2] == stack[stack_size - 1]);
				stack[stack_size - 2] = stack[stack_size - 2] == stack[stack_size - 1];
				++stack_size;
				$$ = BOOLEAN_T;
			} else {
				yyerror("[Erreur] '==' de typage");
				stack[stack_size - 2] = 0;
				stack[stack_size - 1] = 0;
				stack_size -= 2;
				$$ = ERROR_TYPE;
				/* si l'erreur vient de $1, on remonte $1 */
			}
		} | expr NEQ expr {
			if (is_same_type(2, $1, $3, ARITHMETIC_T, BOOLEAN_T)) {
				stack[stack_size - 2] = stack[stack_size - 2] != stack[stack_size - 1]; 
				++stack_size;
				$$ = BOOLEAN_T;
			} else {
				yyerror("[Erreur] '!=' de typage");
				stack[stack_size - 2] = 0;
				stack[stack_size - 1] = 0;
				stack_size -= 2;
				$$ = ERROR_TYPE;
			}
		} | expr AND expr {
			if (is_same_type(1, $1, $3, BOOLEAN_T)) {
				// stack[stack_size - 2] = stack[stack_size - 2] && stack[stack_size - 1];
				stack[stack_size - 2] *= stack[stack_size - 1];
				++stack_size;
				$$ = $1; // $1 = BOOLEAN_T
			} else if ($1 != BOOLEAN_T) {
				if ($1 == ARITHMETIC_T) {
					$$ = ERROR_TYPE;
				} else {
					$$ = $1; // = ARITHMETIC_T
				}
			} else {
				if ($3 == ARITHMETIC_T) {
					$$ = ERROR_TYPE;
				} else {
					$$ = $3; // = ARITHMETIC_T
				}
			}
		} | expr OR expr {
			if (is_same_type(1, $1, $3, BOOLEAN_T)) {
				// stack[stack_size - 2] = stack[stack_size - 2]  stack[stack_size - 1];
				stack[stack_size - 2] += stack[stack_size - 1];
				++stack_size;
				$$ = $1; // $1 = BOOLEAN_T
			} else if ($1 != BOOLEAN_T) {
				if ($1 == ARITHMETIC_T) {
					$$ = ERROR_TYPE;
				} else {
					$$ = $1; // = ARITHMETIC_T
				}
			} else {
				if ($3 == ARITHMETIC_T) {
					$$ = ERROR_TYPE;
				} else {
					$$ = $3; // = ARITHMETIC_T
				}
			}
		} | NUMBER {
			stack[stack_size] = $1; /* la taille de la pile est la valeur du chiffre */
			++stack_size; /* augmente la hauteur de la pile */
			printf("NUMBER : %d - stack_size : %lu\n", $1, stack_size);
			/* on met dans la pile ARITHMETIC_T pour dire que le chiffre */
			$$ = ARITHMETIC_T;
		} | BOOLEAN {
			stack[stack_size] = $1; /* $1 va valoir 0 ou 1 yyval.integer */
			printf("BOOLEAN : %d\n", stack[stack_size]);
			++stack_size;
			$$ = BOOLEAN_T;
		}
	;
%%
	
int is_same_type(size_t size_args, type_synth $1, type_synth $3, ...) {
	va_list args;
	va_start(args, $3);
	int found = 0;
	type_synth type;
	for (int i = 0; i < size_args; i++) {
		type = (type_synth) va_arg(args, type_synth);
		if ($1 == type && $3 == type) {
			found = 1;
			break;
		}
	}
	va_end(args);
	// printf("found %d\n", found);
	return found;
}
	
void yyerror(char const *s) {
	fprintf(stderr, "%s\n", s);
}
	
void print_stack() {
	fprintf(stdout, "== PRINTABLE STACK  ==\n");
	fprintf(stdout, "stack_size : %lu\n", stack_size);
	for (int i = stack_size - 1; i >= 0; i--) {
		fprintf(stdout, "|%d|\n", stack[i]);
	}
}
	
int main(void) {
	yyparse();
	return EXIT_SUCCESS;
}
