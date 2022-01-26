%{ /* expr2.l */
	#include "expr2.tab.h"
%}
%option noyywrap
%%
[[:digit:]]+ return NUMBER;
[[:blank:]]
.|\n return yytext[0];
%%
