# Génération du fichier C qui fait fonctionner les automates et le programme 
flex -D_POSIX_SOURCE --nounput -DYY_NO_INPUT fichier.l
# Création du programme d'analyse lexicale à partir du fichier généré(lex.yy.c)
gcc -std=c11 -pedantic -Wall lex.yy.c -lfl
# Indication du fichier à analyser de manière lexicale
./a.out  < fichier_code_source_c.txt


# Bison
bison fichier.y
gcc -std=c11 -pedantic -Wall -ly fichier.tab.c


# Commandes
flex -D_POSIX_SOURCE -DYY_NO_INPUT --nounput --header-file=lex.yy.h ex1.l
bison  ex1.y -d -v --graph
flex -D_POSIX_SOURCE -DYY_NO_INPUT --nounput ex1.l
gcc -DYYDEBUG -g -std=c11 -pedantic -Wall lex.yy.c -c
gcc -DYYDEBUG -g -std=c11 -pedantic -Wall ex1.tab.c -c
gcc lex.yy.o ex1.tab.o -o ex1 -lfl

# Makefile
make
./ex3
