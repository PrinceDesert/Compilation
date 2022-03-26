%{
	#include <ctype.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <stdbool.h>
	#include <stdarg.h>
	#include <string.h>
	#include <math.h>
	#include <limits.h>
	#include "typesynth_expression.h"
	#include "types.h"
	#include "stable.h"
	
	int yylex(void);
	void yyerror(char const *);
	
	void get_symbol_from_type_synth_expression(symbol_type *symbol, type_synth_expression *tse);
	// Check type
	int is_same_type(size_t size_args, type_synth_expression $1, type_synth_expression $3, ...); /* $1 == T_BOOLEAN && $3 == T_BOOLEAN && value == T_BOOLEAN*/
	// Label asm
	static unsigned int new_label_number();
	static void create_label(char *buf, size_t buf_size, const char *format, ...);
	void fail_with(const char *format, ...);
	
	#define BUFFER_SIZE_MAX 256
	/**
		Dans le code assembleur :
		jmpc, le bit c est positionné (== 1), alors jumpc (écrit dans la doc de asm), pareil pour le bit z
	*/
	char lbl_s_errordiv[BUFFER_SIZE_MAX];
	symbol_table_entry *symbol;
	
	
	#define stack_if_CAPACITY 4096
	static int stack_if[stack_if_CAPACITY];
	static size_t stack_if_size = 0;
	
	
	/**
	 * pour une fonction factorielle 3
	 * empile 3 en haut de la pile
	 * push ax
	 * const dx,factorielle
	 * call
	 * ret retour au départ
	 * dans factorielle
	 * cp cx,sp
	 * const bx,2
	 * sub cx,bx -> permet de se retrouver sur l'argument de la pile
	*/
	
%}
%union {
	int integer;
	bool boolean;
	type_synth_expression state; /* conserve pour les erreurs de typage */
	char id[64]; /* nom de la variable */
	symbol_type stype;
	type_synth_expression selection_state;
	type_synth_expression iteration_state;
}

%token<integer> NUMBER /* le integer est relié à l'union -> integer repéré par flex */
%token<boolean> BOOLEAN /* le boolean est relié à l'union −> boolean repéré par flex  */
%token<id> ID /* on les met en token car pas de on écrit pas de règle sur ce type */
%token<stype> TYPE

%token IF ELSE FOR WHILE

/* Tuto : pour utiliser le $$ comme dans expression, il faut le déclarer en tant que type */ 
%type<state> expression /* le state est relié au champ de l'union state */
%type<state> declaration
%type<state> statement
%type<selection_state> selection_statement
%type<iteration_state> iteration_statement

/* associativité à gauche et priorité des opérateurs (page 144 diaporama)*/
/* EQ = EQUALS, NEQ = NOT EQUALS priorité plus faible */
%left AND OR
%left EQ NEQ
%left GT LT
%left '+''-'
%left '*''/''%''^'

/* lignes = axiome */
%start lignes
%%
	lignes :
		lignes error '\n'		{ yyerrok; }
		| expression error '\n'		{ yyerrok; }
		| error '\n'			{ yyerrok; }
		| lignes expression '\n'		{ /*printf("%d\n", stack_if[0]); stack_if_size = 0;*/ }
		| lignes '\n'
		| expression '\n'				{ /*printf("%d\n", stack_if[0]); stack_if_size = 0;*/ }
		| lignes declaration '\n'
		| lignes statement_list '\n'
		| declaration '\n'
		| '\n'
	;
	
	statement_list : statement | statement_list statement ;
	statement 
		: selection_statement 
		| iteration_statement
		| expression_statement
	;
	
	selection_statement :
		IF '(' expression ')' statement ELSE statement {
			
		} | IF '(' expression ')' statement {
			/* expression doit etre booléen */
			printf("if recognize\n");
			if ($3 == T_BOOLEAN) {
				unsigned int ln = new_label_number();
				stack_if[stack_if_size++] = ln;
				--stack_if_size;
				
				char lbl_if[BUFFER_SIZE_MAX];
				create_label(lbl_if, BUFFER_SIZE_MAX, "%s:%u", "if", ln);
				
				
				printf("\tpop ax\n");
				// si ax true alors fait le if
				// sinon fait pas 
				
				$$ = T_BOOLEAN;
			} else {
				yyerror("[Erreur] IF expression pas booléen");
				$$ = ERROR_TYPE;
			}
			
		}
	;
	
	iteration_statement
		: WHILE '(' expression ')' statement
		| FOR '(' expression_statement expression_statement ')' statement
		| FOR '(' expression_statement expression_statement expression ')' statement
		;
	
	expression_statement 
		: ';'
		| expression ';'
		;
	
	
	
	declaration :
		TYPE ID ';' {
			// printf("déclaration de la variable %s\n", $2);
			// new_symbol_table_entry($2);
			// vérifier si ça existe pas déja
			// et on lui affecte un type
			// on remplit la structure symbol_table_entry symbol_table_entry->DESC
			// printf("type : %d - name : %s\n", $1, $2);
			// $$ = T_BOOLEAN;
			
		} | TYPE ID '=' expression ';' {
			// TYPE : types.h
			// expression : typesynth_expressionession.h
			// -> get_symbol_from_type_synth_expression
			type_synth_expression tse = $4;
			symbol_type *s = malloc(sizeof(symbol_type));
			get_symbol_from_type_synth_expression(s, &tse);
			
			if (COMPATIBLE_TYPES($1, *s)) {
				char varname[64];
				sprintf(varname, "%s", $2);
				symbol = search_symbol_table(varname);
				if (symbol == NULL || strncmp(symbol->name, varname, sizeof(char) * strlen(varname)) != 0) {
					symbol = new_symbol_table_entry(varname);
					symbol->class = GLOBAL_VARIABLE;
					symbol->desc[0] = $1; // le type de la variable dans desc[0] comme c écrit dans types.h
					char lbl_varname[BUFFER_SIZE_MAX];
					create_label(lbl_varname, BUFFER_SIZE_MAX, "%s:%s", "var", varname);
					printf("\tpop bx\n");
					printf("\tconst bx,%s\n", lbl_varname); // est ce qu'il faut l'enregistrer dans une liste ?
					printf("\tstorew ax,bx\n");
					printf("\tpush ax\n");
					$$ = $4;
				} else {
					fail_with("Erreur, la variable %s existe déja dans la table des symboles !\n", varname);
				}
			} else {
				yyerror("[Erreur] déclaration, erreur de typage");
				$$ = ERROR_TYPE;
			}
			free(s);
		}
	;
	
	expression :
		'(' expression ')' {
			/* on fait rien sur la pile sur les parenthèses, on remonte juste l'expressionession = $2 */
			$$ = $2;
		} | expression '+' expression {
			/* $1 = expression, $2 = '+', $3 = expression */
			if (is_same_type(1, $1, $3, T_INT)) {
				printf("\tpop ax\n"); // dépile la pile dont la valeur est mise dans ax
				printf("\tpop bx\n"); // dépile la pile dont la valeur est mise dans bx
				printf("\tadd ax,bx\n"); // fait le plus de ax+bx que on met sur ax
				printf("\tpush ax\n"); // push ax sur la pile qui a le nouveau résultat
				$$ = T_INT;
			} else {
				yyerror("[Erreur] '+' de typage");
				$$ = ERROR_TYPE;
			}
		} | expression '-' expression {
			if (is_same_type(1, $1, $3, T_INT)) {
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tsub ax,bx\n");
				printf("\tpush ax\n");
				$$ = T_INT;
			} else {
				yyerror("[Erreur] '*' de typage");
				$$ = ERROR_TYPE;
			}
		} | expression '*' expression {
			 /* Si $1 == ERROR || $3 == ERROR pas de multiplication */
			if (is_same_type(1, $1, $3, T_INT)) {
				printf("\tpop ax\n");
				printf("\tpop bx\n");
				printf("\tmul ax,bx\n");
				printf("\tpush ax\n");
				$$ = T_INT;
			} else {
				yyerror("[Erreur] '*' de typage");
				$$ = ERROR_TYPE;
			}
		} | expression '/' expression {
			/* $1 = expression, $2 = aucun car pas de non terminal mais un terminal '/', $3 = expression et test division par zéro */
			if (is_same_type(1, $1, $3, T_INT)) {
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
				$$ = T_INT;
			} else {
				yyerror("[Erreur] '/' de typage");
				$$ = ERROR_TYPE;
			}
		} | expression '%' expression {
			if (is_same_type(1, $1, $3, T_INT)) {
				$$ = T_INT;
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
		} | expression '^' expression {
			if (is_same_type(1, $1, $3, T_INT)) {
				$$ = T_INT;
			} else {
				yyerror("[Erreur] '^' de typage");
				$$ = ERROR_TYPE;
			}
		} | expression EQ expression {
			if (is_same_type(2, $1, $3, T_INT, T_BOOLEAN)) {
				
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
				
				$$ = T_BOOLEAN;
			} else {
				yyerror("[Erreur] '==' de typage");
				$$ = ERROR_TYPE; /* si l'erreur vient de $1, on remonte $1 */
			}
		} | expression NEQ expression {
			if (is_same_type(2, $1, $3, T_INT, T_BOOLEAN)) {
				
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
				
				$$ = T_BOOLEAN;
			} else {
				yyerror("[Erreur] '!=' de typage");
				$$ = ERROR_TYPE;
			}
		} | expression AND expression {
			// example : true && true, true && false 
			if (is_same_type(1, $1, $3, T_BOOLEAN)) {
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tand ax,bx\n");
				printf("\tpush ax\n");
				$$ = $1; // $1 = T_BOOLEAN
			} else if ($1 != T_BOOLEAN) {
				if ($1 == T_INT) {
					$$ = ERROR_TYPE;
				} else {
					$$ = $1; // = T_INT
				}
			} else {
				if ($3 == T_INT) {
					$$ = ERROR_TYPE;
				} else {
					$$ = $3; // = T_INT
				}
			}
		} | expression OR expression {
			// example : true || true, true || false
			if (is_same_type(1, $1, $3, T_BOOLEAN)) {
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tor ax,bx\n");
				printf("\tpush ax\n");
				$$ = $1; // $1 = T_BOOLEAN
			} else if ($1 != T_BOOLEAN) {
				if ($1 == T_INT) {
					$$ = ERROR_TYPE;
				} else {
					$$ = $1; // = T_INT
				}
			} else {
				if ($3 == T_INT) {
					$$ = ERROR_TYPE;
				} else {
					$$ = $3; // = T_INT
				}
			}
		} | expression GT expression {
			if (is_same_type(1, $1, $3, T_INT)) {
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
				$$ = T_BOOLEAN; // remonte un booléan comme résultat
			} else {
				$$ = ERROR_TYPE;
			}
		} | expression LT expression {
			if (is_same_type(1, $1, $3, T_INT)) {
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
				$$ = T_BOOLEAN;
			} else {
				$$ = ERROR_TYPE;
			}
		} | NUMBER {
			// Affiche le code asm asipro correspondant
			printf("\tconst ax,%d\n", $1); // met la valeur dans le registre ax
			printf("\tpush ax\n"); // Push sur la pile, et donc ax n'est plus utilisé et peut pas besoin d'utiliser bx
			$$ = T_INT;
		} | BOOLEAN {
			printf("\tconst ax,%d\n", $1); // met la valeur dans le registre ax
			printf("\tpush ax\n"); // Push sur la pile
			$$ = T_BOOLEAN;
		}
	;
%%

/**
 * Comme dans la conception, j'ai décidé de séparé les types expressionessions
 * de ce des symboles d'une déclaration (ex : une erreur de type)
 * cette fonction sert à récupèrer le type de symbole du type de l'expressionession
*/
void get_symbol_from_type_synth_expression(symbol_type *symbol, type_synth_expression *tse) {
	if (tse == NULL) return;
	if (symbol == NULL) return;
	if (*tse == T_INT) {
		*symbol = INT_T_LVALUE;
	} else if (*tse == T_BOOLEAN) {
		*symbol = BOOL_T_LVALUE;
	}
}
	
int is_same_type(size_t size_args, type_synth_expression $1, type_synth_expression $3, ...) {
	va_list args;
	va_start(args, $3);
	int found = 0;
	type_synth_expression type;
	for (int i = 0; i < size_args; i++) {
		type = (type_synth_expression) va_arg(args, type_synth_expression);
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
	
	// Génère les statementuctions du début pour l'asm asipro avant l'analyse grammaticale
	printf("; Généré sur bison\n\n");
	
	printf("; Permet de passer la zone de stockage des constantes\n");
	printf("\tconst ax,debut\n");
	printf("\tjmp ax\n");
	
	// Déclarations des constantes (strings, int) qui peuvent être utiliser
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	printf("; Début de la zone de stockage des constantes\n");
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	
	// String pour division par zéro
	create_label(lbl_s_errordiv, BUFFER_SIZE_MAX, "%s:%s:%u", "s_err", "div0", new_label_number());
	printf("\n");
	printf(":%s\n", lbl_s_errordiv);
	printf("@string \"Erreur de division par 0\\n\"\n");
	printf("\n");
	
	
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	printf("; Fin de la zone de stockage des constantes\n");
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\n");
	
	/*
	printf(";;;;;;;;;;;;;;;;;;;;\n");
	printf("; Début réel du code\n");
	printf(";;;;;;;;;;;;;;;;;;;;\n");
	*/
	
	printf(";;;;;;;;;;;;;;;;;;;;;\n");
	printf("; Fonction principale\n");
	printf(";;;;;;;;;;;;;;;;;;;;;\n");
	printf(":debut\n");
	printf("; Préparation de la pile\n");
	printf("\tconst bp,pile\n"); // bp : fond de la pile
	printf("\tconst sp,pile\n"); // sp : sommet de la pile
	printf("\tconst ax,2\n");
	printf("\tsub sp,ax\n"); // on fait la soustraction pour mettre le sommet de pile à - 2
	
	// Analyse grammaticale
	printf("; Résultat de bison\n");
	yyparse();

	// Génère les statementuctions de fin pour l'asm asipro avant l'analyse grammaticale
	/*
	printf("; Pour afficher la valeur calculée, qui se trouve normalement en sommet de pile\n");
	printf("\tcp ax,sp\n");
	printf("\tcallprintfd ax\n");
	printf("\tend\n");
	*/
	printf("\n");
	
	
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	printf("; Début de stockage de la zone de pile\n");
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	printf(":pile\n");
	printf("@int 0\n");
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	printf("; Fin de stockage de la zone de pile\n");
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	
	
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	printf("; Début de déclaration des variables\n");
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	// L'initialisation des variables à zéro
	// est ce qu'il faut faire l'intialisation des variables à la fin ?
	for (symbol_table_entry *ste = symbol; ste != NULL; ste = ste->next) {
		printf(":var:%s\n", ste->name);
		printf("@int 0\n");
	}
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	printf("; Fin de déclaration des variables\n");
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	
	
	return EXIT_SUCCESS;
}
