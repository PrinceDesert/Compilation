/**
	flex -D_POSIX_SOURCE --nounput -DYY_NO_INPUT ex2.l
	gcc -std=c11 -pedantic -Wall lex.yy.c -lfl
	./a.out  < ex2.c
*/
%%
if printf("<IF>"); /* Remplace le if par <IF> */
else printf("<ELSE>"); /* Remplace le else par <ELSE> */ 
"/*" printf("<SE>"); /* Remplace le début de commentaire par <SE> */
"*/" printf("<ASE>"); /* Remplace la fin de commentaire par <ASE> */
"\\n" printf("<ASN>"); /* Remplace un \n rencontrée par <ASN> */
"("|"["|"{" printf("<PO>"); /* Remplace (, [, { par <PO> */
")"|"]"|"}" printf("<PF>");  /* Remplace ), ], } par <PF> */
"?"+ printf("<?;%s>",yytext); /* affiche les ? rencontrées */
.; // fait rien

%%
int yywrap() {
	return 1;
}
int main() {
	yylex();
	return 0;
}
