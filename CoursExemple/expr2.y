%{ /* expr2.y */
	#include <ctype.h>
	#include <stdio.h>
	int yylex();
	void yyerror (char const *);
%}
%token NUMBER
%%
S: S E '\n' | S '\n' | E '\n' | '\n';
E : E '+' F | F;
F : F '*' T | T;
T: '(' E ')' | NUMBER;
%%

void yyerror (char const *s) {
	fprintf(stderr, "%s", s);
}

