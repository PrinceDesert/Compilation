# Génération du fichier C qui fait fonctionner les automates et le programme 
flex -D_POSIX_SOURCE --nounput -DYY_NO_INPUT fichier.l
# Création du programme d'analyse lexicale à partir du fichier généré(lex.yy.c)
gcc -std=c11 -pedantic -Wall lex.yy.c -lfl
# Indication du fichier à analyser de manière lexicale
./a.out  < fichier_code_source_c.txt
