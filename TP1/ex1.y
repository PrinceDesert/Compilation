%{
	#include <ctype.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include "state.h"
	int yylex(void);
	void yyerror(char const *);
	#define STACK_CAPACITY 50
	static int stack[STACK_CAPACITY];
	static size_t stack_size = 0;
	void print_stack();
%}
%union {
	int integer;
	status state;
}
%token<integer> NUMBER
%type<state> expr

/* associativité à gauche et priorité des opérateurs */
%left '+''-'
%left '*''/''%'

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
			if ($1 == VALID && $3 == VALID) {
				stack[stack_size - 2] += stack[stack_size - 1];
				--stack_size;
				$$ = VALID;
			} else {
				$$ = ERROR;
			}
		} | expr '-' expr {
			stack[stack_size - 2] -= stack[stack_size - 1];
			--stack_size;
		} | expr '*' expr {
			 /* Si $1 == ERROR || $3 == ERROR pas de multiplication */
			if ($1 == VALID && $3 == VALID) {
				stack[stack_size - 2] *= stack[stack_size - 1];
				--stack_size;
				$$ = VALID;
			} else {
				stack[stack_size - 2] = 0;
				stack[stack_size - 1] = 0;
				stack_size -= 2;
				$$ = ERROR;
			}
		} | expr '/' expr {			
			print_stack();
			/* $1 = expr, $2 = aucun car pas de non terminal mais un terminal '/', $3 = expr et test division par zéro */
			if ($1 == VALID && $3 == VALID && stack[stack_size - 1] != 0) {
				printf("DIVISION VALID : %d / %d\n", stack[stack_size - 2], stack[stack_size - 1]);
				stack[stack_size - 2] /= stack[stack_size - 1];
				--stack_size;
				$$ = VALID;
			} else {
				yyerror("[Erreur] Division par zéro");
				fprintf(stderr, "DIVISION NOT VALID : %d / %d\n", $1, $3);
				fprintf(stderr, "Test condition : ($1 == VALID = %d) && ($3 == VALID = %d) && ($$ == ERROR = %d)\n", $1 == VALID, $3 == VALID, $$ == ERROR);
				stack[stack_size - 2] = 0;
				stack[stack_size - 1] = 0;
				stack_size -= 2;
				$$ = ERROR;
			}
			print_stack();
		} | expr '%' expr {
			if ($1 == VALID && $3 == VALID && stack[stack_size - 1] != 0) {
				printf("MODULO VALID : %d / %d\n", stack[stack_size - 2], stack[stack_size - 1]);
				stack[stack_size - 2] %= stack[stack_size - 1];
				--stack_size;
				$$ = VALID;
			} else {
				yyerror("[Erreur] Modulo par zéro");
				fprintf(stderr, "DIVISION NOT VALID : %d / %d\n", $1, $3);
				fprintf(stderr, "Test condition : ($1 == VALID = %d) && ($3 == VALID = %d) && ($$ == ERROR = %d)\n", $1 == VALID, $3 == VALID, $$ == ERROR);
				stack[stack_size - 2] = 0;
				stack[stack_size - 1] = 0;
				stack_size -= 2;
				$$ = ERROR;
			}
		} | NUMBER {
			stack[stack_size] = $1; /* la taille de la pile est la valeur du chiffre */
			++stack_size; /* augmente la hauteur de la pile */
			printf("NUMBER : %d - stack_size : %lu\n", $1, stack_size);
			/* on met dans la pile VALID pour dire que le chiffre est OK */
			$$ = VALID;
		}
	;
%%

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
