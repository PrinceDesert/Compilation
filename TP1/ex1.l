/**
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
  #include <limits.h>
  #include "ex1.tab.h"
  void string_to_int(int *v, const char *s);
%}
%option noyywrap
%%
[[:digit:]]+               { int x; string_to_int(x, yytext); }
[[:blank:]]
.|\n                       { printf("%s", yytext); }
%%

void string_to_int(int *r, const char *s) {
  char *p;
  long v;
  errno = 0;
  v = strtol(s, &p, 10);
  if ( ( *p != '\0' || ( errno == ERANGE 
                     && ( v == LONG_MIN || v == LONG_MAX ) ) ) 
       || ( v < INT_MIN || v > INT_MAX ) ) {
    fprintf(stderr, "Error converting string to int\n");
    exit(EXIT_FAILURE);
  } 
  *r = v;
}
