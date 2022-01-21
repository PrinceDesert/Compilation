/**
	Étape 1 : Génération du fichier C qui fait fonctionner les automates et le programme 
		flex -D_POSIX_SOURCE --nounput -DYY_NO_INPUT ex3.l
	Étape 2 : Création du programme d'analyse lexicale
		gcc -std=c11 -pedantic -Wall lex.yy.c -lfl
	Étape 3 : Indication du fichier à analyser de manière lexicale 
		./a.out  < ex3.c
	Exercice :
	Ecrire un programme flex qui remplace dans un texte chaque lettre par sa
	suivante en conservant la casse (a par b, B par C, z par a). 
	Exemple pour ”Je me sens VRAIMENT bien !” : Kf nf tfot WSBJNFOU cjfo!
	(Si la lettre 'z' ou 'Z' est dépassée alors retour à 'a' ou 'A')
*/
%%  
[a-yA-Y] printf("%c", (*yytext)+1);
z printf("a");
Z printf("A");
<<EOF>> return 0;

%%
int yywrap() {
	return 1;
}
int main() {
	yylex();
	return 1;
}
