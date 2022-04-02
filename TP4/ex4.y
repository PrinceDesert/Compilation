%{
	#include <ctype.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <stdbool.h>
	#include <stdarg.h>
	#include <string.h>
	#include <math.h>
	#include <limits.h>
	#include <typesynth_expression.h>
	#include <types.h>
	#include <stable.h>
	
	#define BUFFER_SIZE_MAX 256
	
	int yylex(void);
	void yyerror(char const *);
	
	int is_same_type(size_t size_args, type_synth_expression $1, type_synth_expression $3, ...); /* $1 == T_BOOLEAN && $3 == T_BOOLEAN && value == T_BOOLEAN*/
	static unsigned int new_label_number();
	static void create_label(char *buf, size_t buf_size, const char *format, ...);
	void fail_with(const char *format, ...);
	void get_symbol_from_type_synth_expression(symbol_type *symbol, type_synth_expression *tse);
	type_synth_expression *get_type_synth_expression_from_symbol(type_synth_expression *type, symbol_type *symbol);
	
	
	/**
		Dans le code assembleur :
		jmpc, le bit c est positionné (== 1), alors jumpc (écrit dans la doc de asm), pareil pour le bit z
	*/
	char lbl_s_errordiv[BUFFER_SIZE_MAX];
	symbol_table_entry *symbol;
	
	
	#define stack_if_CAPACITY 4096
	static size_t stack_if[stack_if_CAPACITY];
	static size_t stack_if_size = 0;
	
	// Fichier assembleur
	FILE *file;
	
	
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
	
	/**
	Fonction :
	
	pile :
	les arguments sur la pile
	et les variables en arguments
	
	*/
	
	
	
	
	
%}
%union {
	int integer;
	bool boolean;
	type_synth_expression state; /* conserve pour les erreurs de typage */
	char id[64]; /* nom de la variable */
	symbol_type stype;
}

%token<integer> NUMBER /* le integer est relié à l'union -> integer repéré par flex */
%token<boolean> BOOLEAN /* le boolean est relié à l'union −> boolean repéré par flex  */
%token<id> ID /* met en token car pas de on écrit pas de règle sur ce type */
%token<stype> TYPE
%token IF ELSE FOR WHILE
%token PRINT RETURN



/* Tuto : pour utiliser le $$ comme dans expression, il faut le déclarer en tant que type */ 
%type<state> expression /* le state est relié au champ de l'union state */
%type<state> declaration
%type<state> statement selection_statement iteration_statement print_statement

/* associativité à gauche et priorité des opérateurs (page 144 diaporama)*/
/* EQ = EQUALS, NEQ = NOT EQUALS priorité plus faible */
%left AND OR
%left EQ NEQ
%left GT LT
%left '+''-'
%left '*''/''%''^'

/* lignes = axiome */
%start program
%%
	/*lignes :
		lignes error '\n'		{ yyerrok; }
		| expression error '\n'		{ yyerrok; }
		| error '\n'			{ yyerrok; }
		| lignes expression '\n'		{  }
		| lignes '\n'
		| expression '\n'				{ }
		| declaration_list '\n'
		| statement_list '\n'
		| '\n'
	;*/
	
	program
		: declaration_list statement_list
		;
		
	declaration_list 
		: declaration_list declaration
		| declaration
		;
	

	
	statement_list : statement_list statement | statement;
	statement
		: compound_statement
		| selection_statement 
		| iteration_statement
		| expression_statement
		| print_statement
		| return_statement 
	;
	
	compound_statement
		: '{' '}'
		| '{' statement_list '}'
		| '{' declaration_list '}'
		| '{' declaration_list statement_list '}'
		;
		
	selection_statement :
		IF '(' expression ')' begin_if statement end_if else statement fi {
			if ($3 == T_BOOLEAN) {
				char lbl_beginif[BUFFER_SIZE_MAX];
				create_label(lbl_beginif, BUFFER_SIZE_MAX, "%s:%u", "begin_if", stack_if[stack_if_size]);
				char lbl_endif[BUFFER_SIZE_MAX];
				create_label(lbl_endif, BUFFER_SIZE_MAX, "%s:%u", "end_if", stack_if[stack_if_size]);
				
				// Dépile le booléen de l'expression
				fprintf(file, "DEMARRAGE\n");
				fprintf(file, "\tpop ax\n");
				
				// Compare si la condition est fausse, saut à la fin du if
				
				fprintf(file, "\tconst cx,%s\n", lbl_endif);
				fprintf(file, "\tcmp ax,0\n");
				fprintf(file, "\tjmpc cx\n");
				fprintf(file, "\tconst cx,%s\n", lbl_beginif);
				fprintf(file, "\tjmp cx\n");
				
				fprintf(file, "\tjmp ax\n");
				fprintf(file, ":%s\n", lbl_beginif);
				fprintf(file, ":%s\n", lbl_endif);
				
				$$ = T_BOOLEAN;
				
			} else {
				yyerror("[Erreur] IF expression pas booléen");
				$$ = ERROR_TYPE;
			}
		}
	;
	
	else :
		ELSE statement
		| %empty
		;
	
	begin_if : %empty {
		unsigned int ln = new_label_number();
		stack_if[stack_if_size++] = ln;
		char lbl_else[BUFFER_SIZE_MAX];
		create_label(lbl_else, BUFFER_SIZE_MAX, "%s:%u", "else", stack_if[stack_if_size]);
		
		// test la valeur de sp si faux saute à else:1
		fprintf(file, "\tconst ax,sp\n");
		fprintf(file, "\tconst bx,%s\n", lbl_else);
		fprintf(file, "\tcmp ax,0\n");
		fprintf(file, "\tjmpc ax\n");
		
	}
	;
	
	end_if : %empty {
		char lbl_fi[BUFFER_SIZE_MAX];
		create_label(lbl_fi, BUFFER_SIZE_MAX, "%s:%u", "fi", stack_if[stack_if_size]);
		char lbl_else[BUFFER_SIZE_MAX];
		create_label(lbl_else, BUFFER_SIZE_MAX, "%s:%u", "else", stack_if[stack_if_size]);
		
		// saute fi:1
		fprintf(file, "\tconst ax,%s\n", lbl_fi);
		fprintf(file, "\tjmp ax\n");
		// étiquette else:1
		fprintf(file, ":%s\n", lbl_else);
	}
	;
	
	fi : %empty {
		// fin de la condition
		char lbl_fi[BUFFER_SIZE_MAX];
		create_label(lbl_fi, BUFFER_SIZE_MAX, "%s:%u", "fi", stack_if[stack_if_size]);
		fprintf(file, ":%s\n", lbl_fi);
		
		// Dépile le if sortie
		stack_if[stack_if_size--] = 0;
	}
	;
	
	
	iteration_statement
		: WHILE '(' expression ')' statement {
			
		}
		| FOR '(' expression_statement expression_statement ')' statement {
			
		}
		| FOR '(' expression_statement expression_statement expression ')' statement {
			$$ = ERROR_TYPE;
		}
		;
	
	expression_statement
		: ';'
		| expression ';'
		| ID '=' expression ';' {
			char varname[64];
			sprintf(varname, "%s", $1);
			symbol = search_symbol_table(varname);
			if (symbol != NULL) {
				char lbl_varname[BUFFER_SIZE_MAX];
				create_label(lbl_varname, BUFFER_SIZE_MAX, "%s:%s", "var", varname);
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tconst bx,%s\n", lbl_varname);
				fprintf(file, "\tstorew ax,bx\n");
				fprintf(file, "\tpush ax\n");
				// $$ = $3; 
			} else {
				fail_with("Erreur, la variable %s n'existe pas dans la table des symboles !\n", varname);
			}
		}
		;
	
	print_statement
		: PRINT '(' expression ')' ';' {
			if ($3 == T_INT || $3 == T_BOOLEAN) {
				fprintf(file, "\tcallprintfd sp\n");
				fprintf(file, "\tpop\n");
			}
		}
		;
	
	return_statement
		: RETURN ';' {}
		| RETURN expression ';' {}
		;

	
	declaration :
		TYPE ID ';' {
			// fprintf(file, "déclaration de la variable %s\n", $2);
			// new_symbol_table_entry($2);
			// vérifier si ça existe pas déja
			// et on lui affecte un type
			// on remplit la structure symbol_table_entry symbol_table_entry->DESC
			// fprintf(file, "type : %d - name : %s\n", $1, $2);
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
					fprintf(file, "\tpop bx\n");
					fprintf(file, "\tconst bx,%s\n", lbl_varname); // est ce qu'il faut l'enregistrer dans une liste ?
					fprintf(file, "\tstorew ax,bx\n");
					fprintf(file, "\tpush ax\n");
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
				fprintf(file, "\tpop ax\n"); // dépile la pile dont la valeur est mise dans ax
				fprintf(file, "\tpop bx\n"); // dépile la pile dont la valeur est mise dans bx
				fprintf(file, "\tadd ax,bx\n"); // fait le plus de ax+bx que on met sur ax
				fprintf(file, "\tpush ax\n"); // push ax sur la pile qui a le nouveau résultat
				$$ = T_INT;
			} else {
				yyerror("[Erreur] '+' de typage");
				$$ = ERROR_TYPE;
			}
		} | expression '-' expression {
			if (is_same_type(1, $1, $3, T_INT)) {
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tsub ax,bx\n");
				fprintf(file, "\tpush ax\n");
				$$ = T_INT;
			} else {
				yyerror("[Erreur] '*' de typage");
				$$ = ERROR_TYPE;
			}
		} | expression '*' expression {
			 /* Si $1 == ERROR || $3 == ERROR pas de multiplication */
			if (is_same_type(1, $1, $3, T_INT)) {
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tmul ax,bx\n");
				fprintf(file, "\tpush ax\n");
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
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_errordiv);
				fprintf(file, "\tdiv ax,bx\n");
				fprintf(file, "\tjmpe cx\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, "\tconst ax,%s\n", lbl_end_div);
				fprintf(file, "\tjmp ax\n");
				fprintf(file, ":%s\n", lbl_errordiv);
				fprintf(file, "\tconst ax,%s\n", lbl_s_errordiv);
				fprintf(file, "\tcallprintfs ax\n");
				fprintf(file, "\tend\n");
				fprintf(file, ":%s\n", lbl_end_div); // si pas d'erreur ça sort sur ce label qui fait rien
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
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tcp dx,ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_errordiv);
				fprintf(file, "\tdiv ax,bx\n");
				fprintf(file, "\tjmpe cx\n");
				fprintf(file, "\tcp cx,dx\n"); // copie dans cx de dx qui contient ax pour l'utiliser plustard
				fprintf(file, "\tcp dx,bx\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, "\tconst ax,%s\n", lbl_end_div);
				fprintf(file, "\tjmp ax\n");
				fprintf(file, ":%s\n", lbl_errordiv);
				fprintf(file, "\tconst ax,%s\n", lbl_s_errordiv);
				fprintf(file, "\tcallprintfs ax\n");
				fprintf(file, "\tend\n");
				fprintf(file, ":%s\n", lbl_end_div);
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tmul ax,dx\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tsub cx,ax\n");
				fprintf(file, "\tpush cx\n");
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
				
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_eqtrue);
				fprintf(file, "\tcmp ax,bx\n");
				fprintf(file, "\tjmpc cx\n");
				fprintf(file, "\tconst ax,0\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_endeqtrue);
				fprintf(file, "\tjmp cx\n");
				fprintf(file, ":%s\n", lbl_eqtrue);
				fprintf(file, "\tconst ax,1\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, ":%s\n", lbl_endeqtrue);
				
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
				
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_neqfalse);
				fprintf(file, "\tcmp ax,bx\n");
				fprintf(file, "\tjmpc cx\n");
				fprintf(file, "\tconst ax,1\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_endneqfalse);
				fprintf(file, "\tjmp cx\n");
				fprintf(file, ":%s\n", lbl_neqfalse);
				fprintf(file, "\tconst ax,0\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, ":%s\n", lbl_endneqfalse);
				
				$$ = T_BOOLEAN;
			} else {
				yyerror("[Erreur] '!=' de typage");
				$$ = ERROR_TYPE;
			}
		} | expression AND expression {
			// example : true && true, true && false 
			if (is_same_type(1, $1, $3, T_BOOLEAN)) {
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tand ax,bx\n");
				fprintf(file, "\tpush ax\n");
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
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tor ax,bx\n");
				fprintf(file, "\tpush ax\n");
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
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_true);
				fprintf(file, "\tsless bx,ax\n");
				fprintf(file, "\tjmpc cx\n");
				fprintf(file, "\tconst ax,0\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_endtrue);
				fprintf(file, "\tjmp cx\n");
				fprintf(file, ":%s\n", lbl_true);
				fprintf(file, "\tconst ax,1\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, ":%s\n", lbl_endtrue);
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
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_true);
				fprintf(file, "\tsless ax,bx\n");
				fprintf(file, "\tjmpc cx\n");
				fprintf(file, "\tconst ax,0\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_endtrue);
				fprintf(file, "\tjmp cx\n");
				fprintf(file, ":%s\n", lbl_true);
				fprintf(file, "\tconst ax,1\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, ":%s\n", lbl_endtrue);
				$$ = T_BOOLEAN;
			} else {
				$$ = ERROR_TYPE;
			}
		} | NUMBER {
			// Affiche le code asm asipro correspondant
			fprintf(file, "\tconst ax,%d\n", $1); // met la valeur dans le registre ax
			fprintf(file, "\tpush ax\n"); // Push sur la pile, et donc ax n'est plus utilisé et peut pas besoin d'utiliser bx
			$$ = T_INT;
		} | BOOLEAN {
			fprintf(file, "\tconst ax,%d\n", $1); // met la valeur dans le registre ax
			fprintf(file, "\tpush ax\n"); // Push sur la pile
			$$ = T_BOOLEAN;
		} | ID {
			symbol_table_entry *ste;
			if ((ste = search_symbol_table($1)) == NULL) {
				yyerror("[Erreur] symbol inconnu");
				$$ = ERROR_TYPE;
			} else {
				type_synth_expression *tse = malloc(sizeof(type_synth_expression));
				if ((tse = get_type_synth_expression_from_symbol(tse, &ste->desc[0])) == NULL) {
					yyerror("[Erreur] symbol non enregistré");
					$$ = ERROR_TYPE;
				}	
				$$ = *tse;
				free(tse);
			}
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
	
type_synth_expression *get_type_synth_expression_from_symbol(type_synth_expression *type, symbol_type *symbol) {
	if (symbol == NULL) return NULL;
	if (type == NULL) return NULL;
	if (*symbol == INT_T) {
		*type = T_INT;
	} else if (*symbol == BOOL_T) {
		*type = T_BOOLEAN;
	}
	return type;
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
	// fprintf(file, "found %d\n", found);
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
	const char *full_filename = "ex4.asm";
	printf("==================================================================\n");
	printf("== Code assembleur ASIPRO généré dans le fichier : %s\n", full_filename);
	printf("== Dès lorsque l'analyse syntaxicale et grammaticale terminée, il faut utiliser ASIPRO et SIPRO pour l'éxécuter\n");
	printf("==================================================================\n");
	
	// Ouverture du fichier d'assembleur pour y écrire le code assembleur
	file = fopen(full_filename, "w");
	if (file == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	
	// Génère les statementuctions du début pour l'asm asipro avant l'analyse grammaticale
	fprintf(file, "; Généré sur bison\n\n");
	
	fprintf(file, "; Permet de passer la zone de stockage des constantes\n");
	fprintf(file, "\tconst ax,debut\n");
	fprintf(file, "\tjmp ax\n");
	
	// Déclarations des constantes (strings, int) qui peuvent être utiliser
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; Début de la zone de stockage des constantes\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	
	// String pour division par zéro
	create_label(lbl_s_errordiv, BUFFER_SIZE_MAX, "%s:%s:%u", "s_err", "div0", new_label_number());
	fprintf(file, "\n");
	fprintf(file, ":%s\n", lbl_s_errordiv);
	fprintf(file, "@string \"Erreur de division par 0\\n\"\n");
	fprintf(file, "\n");
	
	
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; Fin de la zone de stockage des constantes\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\n");
	
	/*
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; Début réel du code\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;\n");
	*/
	
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; Fonction principale\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, ":debut\n");
	fprintf(file, "; Préparation de la pile\n");
	fprintf(file, "\tconst bp,pile\n"); // bp : fond de la pile
	fprintf(file, "\tconst sp,pile\n"); // sp : sommet de la pile
	fprintf(file, "\tconst ax,2\n");
	fprintf(file, "\tsub sp,ax\n"); // on fait la soustraction pour mettre le sommet de pile à - 2
	
	// Analyse grammaticale
	fprintf(file, "; Codé généré à partir de bison\n");
	yyparse();

	// Génère les statementuctions de fin pour l'asm asipro avant l'analyse grammaticale
	/*
	fprintf(file, "; Pour afficher la valeur calculée, qui se trouve normalement en sommet de pile\n");
	fprintf(file, "\tcp ax,sp\n");
	fprintf(file, "\tcallprintfd ax\n");
	fprintf(file, "\tend\n");
	*/
	fprintf(file, "\n");
	
	
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; Début de stockage de la zone de pile\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, ":pile\n");
	fprintf(file, "@int 0\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; Fin de stockage de la zone de pile\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	
	
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; Début de déclaration des variables\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	// L'initialisation des variables initialisées à zéro
	for (symbol_table_entry *ste = symbol; ste != NULL; ste = ste->next) {
		fprintf(file, ":var:%s\n", ste->name);
		fprintf(file, "@int 0\n");
		free_first_symbol_table_entry();
	}
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; Fin de déclaration des variables\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	
	if (fclose(file) == EOF) {
		perror("fclose");
		exit(EXIT_FAILURE);
	}
	
	return EXIT_SUCCESS;
}
