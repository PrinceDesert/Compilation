/**
	Fichier flex
	Étape 1 : Génération du fichier C qui fait fonctionner les automates et le programme 
		flex -D_POSIX_SOURCE --nounput -DYY_NO_INPUT ex1.l
	Étape 2 : Création du programme d'analyse lexicale
		gcc -std=c11 -pedantic -Wall lex.yy.c -lfl
	Étape 3 : Indication du fichier à analyser de manière lexicale 
		./a.out  < exemple.txt
		./a.out  < exemple.c
		
	Ne pas appliquer l'étape 1, 2, 3 mais utiliser le Makefile
	Car ce fichier utilise un fichier(ex1.tab.h) crée par un autre fichier n'a pas encore été crée (par bison = ex1.tab.h)
	Donc si éxécution des étapes 1, 2, 3 = erreur
*/
%{
	#include <stdio.h>
	#include <limits.h>
	#include <stdbool.h>
	#include "typesynth.h"
	#include "ex4.tab.h"
	#include "types.h"
	void string_to_int(int *v, const char *s);
%}
%option noyywrap
%%
[[:digit:]]+				{ string_to_int(&yylval.integer, yytext); return NUMBER; /* return NUMBER pour bison */ }
true						{ yylval.integer = 1; return BOOLEAN; /* return TRUE pour bison */ }
false						{ yylval.integer = 0; return BOOLEAN; /* return FALSE pour bison */ }
==							{ return EQ; }
!= 							{ return NEQ; }
&&							{ return AND; }
\|\| 						{ return OR; }
int							{ yylval.stype = INT_T; return TYPE; }
bool						{ yylval.stype = BOOL_T; return TYPE; }
void						{ yylval.stype = VOID_T; return TYPE; }
[a-zA-Z][a-zA-Z0-9]*		{ sprintf(yylval.id, "%s", yytext); return ID; }
[[:blank:]]					
.|\n						{ return yytext[0]; }
%%

void string_to_int(int *r, const char *s) {
	char *p;
	long v;
	errno = 0;
	v = strtol(s, &p, 10);
	if ( ( *p != '\0'
		|| ( errno == ERANGE && ( v == LONG_MIN || v == LONG_MAX ) ) ) 
		|| ( v < INT_MIN || v > INT_MAX ) ) {
	fprintf(stderr, "Error converting string to int\n");
	exit(EXIT_FAILURE);
	}
	*r = v;
}


