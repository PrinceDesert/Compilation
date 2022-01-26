%{ /* expr2.y */
	#include <ctype.h>
	#include <stdio.h>
	int yylex(void);
	void yyerror (char const *);
%}
%token NUMBER
%%
S: S E '\n' | S '\n' | E '\n' | '\n';
E : E '+' F | F;
F : F '*' T | T;
T: '(' E ')' | NUMBER;
%%

int yylex() {
 int c;
 while ( (c=getchar())!= EOF && isblank(c) ) // eat spaces
 ;
 if ( c == EOF )
 return 0; // Nothing left to read
 if ( isdigit(c) ) {
 while ( (c=getchar())!= EOF && isdigit(c) ) // eat other digits
 ;
 ungetc(c, stdin);
 return NUMBER;
 } else {
 return c;
 }
}

void yyerror (char const *s) {
	fprintf(stderr, "%s", s);
}

