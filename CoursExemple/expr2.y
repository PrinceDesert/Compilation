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

/* return la catégorie de la prochaine unité lexicale sous la forme d'un entier (int) >0 sinon 0 plus rien à lire */
/*
int yylex() {
	int c;
	// eat spaces
	while ( (c=getchar())!= EOF && isblank(c) );
	if ( c == EOF )
		return 0; // Nothing left to read
	if ( isdigit(c) ) {
		// eat other digits
		while ( (c=getchar())!= EOF && isdigit(c) );
		ungetc(c, stdin);
		return NUMBER;
	} else {
		return c;
	}
}*/

void yyerror (char const *s) {
	fprintf(stderr, "%s", s);
}

