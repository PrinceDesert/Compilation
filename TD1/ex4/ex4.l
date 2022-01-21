/**
	Étape 1 : Génération du fichier C qui fait fonctionner les automates et le programme 
		flex -D_POSIX_SOURCE --nounput -DYY_NO_INPUT ex4.l
	Étape 2 : Création du programme d'analyse lexicale
		gcc -std=c11 -pedantic -Wall lex.yy.c -lfl
	Étape 3 : Indication du fichier à analyser de manière lexicale 
		./a.out  < ex4.c
	Exercice :
	Transposer en flex les expressions régulières du premier exercice
*/
%%  
[a-zA-Z][a-zA-Z0-9]*|_[a-zA-Z0-9_]*[a-zA-Z][a-zA-Z0-9_]* printf("<IDENTIF>");
'([^']|'')*' printf("<STRING_PASCAL>");
\"[^\"]+\" printf("<STRING_C>");
([+-]?([0-9]+([.][0-9]*)?|[.][0-9]+))|(0[xX][0-9a-fA-F]+)|(0[1-7][0-7]*) printf("<ENTIER>");
[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)[eE][+-][0-9]+ printf("<REAL_EXPONENT>");

<<EOF>> return 0;
%%
int yywrap() {
	return 1;
}
int main() {
	yylex();
	return 1;
}
