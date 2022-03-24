%{
	#include <stdio.h>
	#include <limits.h>
	#include <stdbool.h>
	#include "typesynth.h"
	#include "ex4.tab.h"
	#include "types.h"
	static void comment(); // commentaire
	void string_to_int(int *v, const char *s);
	unsigned long int numlign = 1;
%}

%option noyywrap

%%
"/*"						{ comment(); }
"//".*						{ /* consomme les commentaires commençant par // puis suivit de n'importe quel(s) caractère(s) */}


[[:digit:]]+				{ string_to_int(&yylval.integer, yytext); return NUMBER; /* return NUMBER pour bison */ }

int							{ yylval.stype = INT_T; return TYPE; }
bool						{ yylval.stype = BOOL_T; return TYPE; }
void						{ yylval.stype = VOID_T; return TYPE; }
string						{ yylval.stype = STRING_T; return TYPE; }
"true"						{ yylval.integer = 1; return BOOLEAN; /* pour bison : true est un booléen */}
"false"						{ yylval.integer = 0; return BOOLEAN; /* pour bison : false est un booléen */}

"=="						{ return EQ; }
"!=" 						{ return NEQ; }
"&&"						{ return AND; }
"||" 						{ return OR; }
">"							{ return GT; }
"<"							{ return LT; }
";"							{ return ';'; }
("{"|"<%")					{ return '{'; }
","							{ return ','; }
":"							{ return ':'; }
"="							{ return '='; }
"("							{ return '('; }
")"							{ return ')'; }
("["|"<:")					{ return '['; }
("]"|":>")					{ return ']'; }
"."							{ return '.'; }
"&"							{ return '&'; }
"!"							{ return '!'; }
"~"							{ return '~'; }
"-"							{ return '-'; }
"+"							{ return '+'; }
"*"							{ return '*'; }
"/"							{ return '/'; }
"%"							{ return '%'; }
"<"							{ return '<'; }
">"							{ return '>'; }
"^"							{ return '^'; }
"|"							{ return '|'; }
"?"							{ return '?'; }

[a-zA-Z][a-zA-Z0-9]*		{ sprintf(yylval.id, "%s", yytext); return ID; }

[[:blank:]]				{ /* fait rien sur espace*/ }
[\t\v\f] 				{ }
\n						{ numlign++; return yytext[0]; }
.						{ fprintf(stderr, "Erreur, lexique inconnu à la ligne %lu -> %s (taille : %d)\n", numlign, yytext, yyleng); return yytext[0]; }
%%

/* yywrap : cette fonction est appellé à la fin du fichier, de sorte que vous pouvez pointer vers un autre fichier et de poursuivre l'analyse de son contenu */
/* Désactiver avec l'option : %option noyywrap */
/* Dans le makefile, -lfl : utiliser la valeur par défault */
/*
int yywrap() {
	return 1;
}
*/
	
// Cette fonction est apellé lorsque flex a rencontré un /*
// et donc comment effectue le traitement de tout ce qu'il y a après le /*
static void comment() {
	int c;
	while ((c = yylex()) != 0) {
		if (c == '*') {
			while ((c = yylex()) == '*');
			if (c == '/') {
				return;
			}
			if (c == 0) {
				break;
			}
		}
	}
	fprintf(stderr, "Erreur commentaire : %s (taille : %d)\n", yytext, yyleng);
	exit(EXIT_FAILURE);
}
	
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
