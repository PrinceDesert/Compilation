%{
	#include <ctype.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <stdbool.h>
	#include <stdarg.h>
	#include <string.h>
	#include <math.h>
	#include <limits.h>
	#include "typesynth.h"
	int yylex(void);
	void yyerror(char const *);
	
	// Check type
	int is_same_type(size_t size_args, type_synth $1, type_synth $3, ...); /* $1 == BOOLEAN_T && $3 == BOOLEAN_T && value == BOOLEAN_T*/
	// Label asm
	static unsigned int new_label_number();
	static void create_label(char *buf, size_t buf_size, const char *format, ...);
	void fail_with(const char *format, ...);
	
	#define BUFFER_SIZE_MAX 256
	
	/**
		* ToDo : 
		* ENelver toutes les divisions par zéro, on utilise plus la stack donc tout enlevé à propos de la stack
		* pour les labels il faut utiliser les fonctions
		* stack_size plus besoin car là il faut écrire dans un fichier asm que on ouvre dans le main
		* division par zéro code assembleur qui le gère, le bit z fl positioné à 1, jumpz que si bit z est à 1
	*/
	char lbl_s_errordiv[BUFFER_SIZE_MAX];
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
%left EQ NEQ GT LT
%left AND OR
%left '+''-'
%left '*''/''%''^'

/* lignes = axiome */
%start lignes
%%
	lignes :
		lignes error '\n'		{ yyerrok; }
		| expr error '\n'		{ yyerrok; }
		| error '\n'			{ yyerrok; }
		| lignes expr '\n'		{ /*printf("%d\n", stack[0]); stack_size = 0;*/ }
		| lignes '\n'
		| expr '\n'				{ /*printf("%d\n", stack[0]); stack_size = 0;*/ }
		| '\n'
	;
	
	expr :
		'(' expr ')' {
			/* on fait rien sur la pile sur les parenthèses, on remonte juste l'expression = $2 */
			$$ = $2;
		} | expr '+' expr {
			/* $1 = expr, $2 = '+', $3 = expr */
			if (is_same_type(1, $1, $3, ARITHMETIC_T)) {
				printf("\tpop ax\n"); // dépile la pile dont la valeur est mise dans ax
				printf("\tpop bx\n"); // dépile la pile dont la valeur est mise dans bx
				printf("\tadd ax,bx\n"); // fait le plus de ax+bx que on met sur ax
				printf("\tpush ax\n"); // push ax sur la pile qui a le nouveau résultat
				$$ = ARITHMETIC_T;
			} else {
				yyerror("[Erreur] '+' de typage");
				$$ = ERROR_TYPE;
			}
		} | expr '-' expr {
			if (is_same_type(1, $1, $3, ARITHMETIC_T)) {
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tsub ax,bx\n");
				printf("\tpush ax\n");
				$$ = ARITHMETIC_T;
			} else {
				yyerror("[Erreur] '*' de typage");
				$$ = ERROR_TYPE;
			}
		} | expr '*' expr {
			 /* Si $1 == ERROR || $3 == ERROR pas de multiplication */
			if (is_same_type(1, $1, $3, ARITHMETIC_T)) {
				printf("\tpop ax\n");
				printf("\tpop bx\n");
				printf("\tmul ax,bx\n");
				printf("\tpush ax\n");
				$$ = ARITHMETIC_T;
			} else {
				yyerror("[Erreur] '*' de typage");
				$$ = ERROR_TYPE;
			}
		} | expr '/' expr {
			/* $1 = expr, $2 = aucun car pas de non terminal mais un terminal '/', $3 = expr et test division par zéro */
			if (is_same_type(1, $1, $3, ARITHMETIC_T)) {
				// Création d'étiquettes uniques
				char lbl_errordiv[BUFFER_SIZE_MAX];
				char lbl_end_div[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_errordiv, BUFFER_SIZE_MAX, "%s:%s:%u", "err", "div0", ln);
				create_label(lbl_end_div, BUFFER_SIZE_MAX, "%s:%s:%u", "fin", "div", ln);
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tconst cx,%s\n", lbl_errordiv);
				printf("\tdiv ax,bx\n");
				printf("\tjmpe cx\n");
				printf("\tpush ax\n");
				printf("\tconst ax,%s\n", lbl_end_div);
				printf("\tjmp ax\n");
				printf(":%s\n", lbl_errordiv);
				printf("\tconst ax,%s\n", lbl_s_errordiv);
				printf("\tcallprintfs ax\n");
				printf("\tend\n");
				printf(":%s\n", lbl_end_div); // si pas d'erreur ça sort sur ce label qui fait rien
				$$ = ARITHMETIC_T;
			} else {
				yyerror("[Erreur] '/' de typage");
				$$ = ERROR_TYPE;
			}
		} | expr '%' expr {
			if (is_same_type(1, $1, $3, ARITHMETIC_T)) {
				$$ = ARITHMETIC_T;
				char lbl_errordiv[BUFFER_SIZE_MAX];
				char lbl_end_div[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_errordiv, BUFFER_SIZE_MAX, "%s:%s:%u", "err", "div0", ln);
				create_label(lbl_end_div, BUFFER_SIZE_MAX, "%s:%s:%u", "fin", "div", ln);
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tcp dx,ax\n");
				printf("\tconst cx,%s\n", lbl_errordiv);
				printf("\tdiv ax,bx\n");
				printf("\tjmpe cx\n");
				printf("\tcp cx,dx\n"); // copie dans cx de dx qui contient ax pour l'utiliser plustard
				printf("\tcp dx,bx\n");
				printf("\tpush ax\n");
				printf("\tconst ax,%s\n", lbl_end_div);
				printf("\tjmp ax\n");
				printf(":%s\n", lbl_errordiv);
				printf("\tconst ax,%s\n", lbl_s_errordiv);
				printf("\tcallprintfs ax\n");
				printf("\tend\n");
				printf(":%s\n", lbl_end_div);
				printf("\tpop ax\n");
				printf("\tmul ax,dx\n");
				printf("\tpush ax\n");
				printf("\tpop ax\n");
				printf("\tsub cx,ax\n");
				printf("\tpush cx\n");
			} else {
				yyerror("[Erreur] '%%' de typage");
				$$ = ERROR_TYPE;
			}
		} | expr '^' expr {
			if (is_same_type(1, $1, $3, ARITHMETIC_T)) {
				$$ = ARITHMETIC_T;
			} else {
				yyerror("[Erreur] '^' de typage");
				$$ = ERROR_TYPE;
			}
		} | expr EQ expr {
			if (is_same_type(2, $1, $3, ARITHMETIC_T, BOOLEAN_T)) {
				
				char lbl_eqtrue[BUFFER_SIZE_MAX];
				char lbl_endeqtrue[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_eqtrue, BUFFER_SIZE_MAX, "%s:%s:%u", "eq", "true", ln);
				create_label(lbl_endeqtrue, BUFFER_SIZE_MAX, "%s:%s:%u", "endeq", "true", ln);
				
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tconst cx,%s\n", lbl_eqtrue);
				printf("\tcmp ax,bx\n");
				printf("\tjmpc cx\n");
				printf("\tconst ax,0\n");
				printf("\tpush ax\n");
				printf("\tconst cx,%s\n", lbl_endeqtrue);
				printf("\tjmp cx\n");
				printf(":%s\n", lbl_eqtrue);
				printf("\tconst ax,1\n");
				printf("\tpush ax\n");
				printf(":%s\n", lbl_endeqtrue);
				
				$$ = BOOLEAN_T;
			} else {
				yyerror("[Erreur] '==' de typage");
				$$ = ERROR_TYPE; /* si l'erreur vient de $1, on remonte $1 */
			}
		} | expr NEQ expr {
			if (is_same_type(2, $1, $3, ARITHMETIC_T, BOOLEAN_T)) {
				
				char lbl_neqfalse[BUFFER_SIZE_MAX];
				char lbl_endneqfalse[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_neqfalse, BUFFER_SIZE_MAX, "%s:%s:%u", "neq", "false", ln);
				create_label(lbl_endneqfalse, BUFFER_SIZE_MAX, "%s:%s:%u", "endneq", "false", ln);
				
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tconst cx,%s\n", lbl_neqfalse);
				printf("\tcmp ax,bx\n");
				printf("\tjmpc cx\n");
				printf("\tconst ax,1\n");
				printf("\tpush ax\n");
				printf("\tconst cx,%s\n", lbl_endneqfalse);
				printf("\tjmp cx\n");
				printf(":%s\n", lbl_neqfalse);
				printf("\tconst ax,0\n");
				printf("\tpush ax\n");
				printf(":%s\n", lbl_endneqfalse);
				
				$$ = BOOLEAN_T;
			} else {
				yyerror("[Erreur] '!=' de typage");
				$$ = ERROR_TYPE;
			}
		} | expr AND expr {
			// example : true && true, true && false 
			if (is_same_type(1, $1, $3, BOOLEAN_T)) {
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tand ax,bx\n");
				printf("\tpush ax\n");
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
			// example : true || true, true || false
			if (is_same_type(1, $1, $3, BOOLEAN_T)) {
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tor ax,bx\n");
				printf("\tpush ax\n");
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
		} | expr GT expr {
			if (is_same_type(1, $1, $3, ARITHMETIC_T)) {
				char lbl_true[BUFFER_SIZE_MAX];
				char lbl_endtrue[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_true, BUFFER_SIZE_MAX, "%s:%s:%u", "gt", "true", ln);
				create_label(lbl_endtrue, BUFFER_SIZE_MAX, "%s:%s:%u", "gt", "endtrue", ln);
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tconst cx,%s\n", lbl_true);
				printf("\tsless bx,ax\n");
				printf("\tjmpc cx\n");
				printf("\tconst ax,0\n");
				printf("\tpush ax\n");
				printf("\tconst cx,%s\n", lbl_endtrue);
				printf("\tjmp cx\n");
				printf(":%s\n", lbl_true);
				printf("\tconst ax,1\n");
				printf("\tpush ax\n");
				printf(":%s\n", lbl_endtrue);
				$$ = BOOLEAN_T; // remonte un booléan comme résultat
			} else {
				$$ = ERROR_TYPE;
			}
		} | expr LT expr {
			if (is_same_type(1, $1, $3, ARITHMETIC_T)) {
				char lbl_true[BUFFER_SIZE_MAX];
				char lbl_endtrue[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_true, BUFFER_SIZE_MAX, "%s:%s:%u", "lt", "true", ln);
				create_label(lbl_endtrue, BUFFER_SIZE_MAX, "%s:%s:%u", "lt", "endtrue", ln);
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tconst cx,%s\n", lbl_true);
				printf("\tsless ax,bx\n");
				printf("\tjmpc cx\n");
				printf("\tconst ax,0\n");
				printf("\tpush ax\n");
				printf("\tconst cx,%s\n", lbl_endtrue);
				printf("\tjmp cx\n");
				printf(":%s\n", lbl_true);
				printf("\tconst ax,1\n");
				printf("\tpush ax\n");
				printf(":%s\n", lbl_endtrue);
				$$ = BOOLEAN_T;
			} else {
				$$ = ERROR_TYPE;
			}
		} | NUMBER {
			// Affiche le code asm asipro correspondant
			printf("\tconst ax,%d\n", $1); // met la valeur dans le registre ax
			printf("\tpush ax\n"); // Push sur la pile, et donc ax n'est plus utilisé et peut pas besoin d'utiliser bx
			$$ = ARITHMETIC_T;
		} | BOOLEAN {
			printf("\tconst ax,%d\n", $1); // met la valeur dans le registre ax
			printf("\tpush ax\n"); // Push sur la pile
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
	
	
// Label asm
static unsigned int new_label_number() {
	static unsigned int current_label_number = 0u;
	if ( current_label_number == UINT_MAX ) {
		fail_with("Error: maximum label number reached!\n");
	}
	return current_label_number++;
}
	
/*
 * Example :
 * char buf1[MAXBUF], char buf2[MAXBUF];
 * unsigned ln = new_label_number();
 * create_label(buf1, MAXBUF, "%s:%u:%s", "loop", ln, "begin");
 * create_label(buf2, MAXBUF, "%s:%u:%s", "loop", ln, "end");
*/
static void create_label(char *buf, size_t buf_size, const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	if ( vsnprintf(buf, buf_size, format, ap) >= buf_size ) {
		va_end(ap);
		fail_with("Error in label generation: size of label exceeds maximum size!\n");
	}
	va_end(ap);
}
	
void fail_with(const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	exit(EXIT_FAILURE);
}
	
	
int main(void) {
	
	// Génère les instructions du début pour l'asm asipro avant l'analyse grammaticale
	printf("; Exercice 1\n\n");
	printf("\tconst ax,debut\n");
	printf("\tjmp ax\n");
	
	// Déclarations des strings qui peuvent être utiliser
	create_label(lbl_s_errordiv, BUFFER_SIZE_MAX, "%s:%s:%u", "s_err", "div0", new_label_number());
	printf("\n");
	printf(":%s\n", lbl_s_errordiv);
	printf("@string \"Erreur de division par 0\\n\"\n");
	printf("\n");
	
	printf(":debut\n");
	printf("; Préparation de la pile\n");
	printf("\tconst bp,pile\n"); // bp : fond de la pile
	printf("\tconst sp,pile\n"); // sp : sommet de la pile
	printf("\tconst ax,2\n");
	printf("\tsub sp,ax\n"); // on fait la soustraction pour mettre le sommet de pile à - 2
	
	// Analyse grammaticale
	printf("; Résultat de bison\n");
	yyparse();

	// Génère les instructions de fin pour l'asm asipro avant l'analyse grammaticale
	printf("; Pour afficher la valeur calculée, qui se trouve normalement en sommet de pile\n");
	printf("\tcp ax,sp\n");
	printf("\tcallprintfd ax\n");
	printf("\tend\n");
	printf("; La zone de pile\n");
	printf(":pile\n");
	printf("@int 0\n");
	
	return EXIT_SUCCESS;
}
