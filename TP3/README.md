Pour ce TP3, le code de l'analyseur grammaticale (bison) est généré en assembleur asipro
Il est ensuite éxécuté avec sipro.

Lorsque l'analyse est terminé, faire un CTRL+D pour fermer l'analyse, pour que yyparse se termine.

# Makefile
(Pour modifier ex3 = nom de l'éxécutable, modifier le dans le makefile)
make
./ex3 > ./asm/test.asm

# Exécuter le code assembleur
asipro ./asm/test.asm executable
sipro executable

# Exemple
1 - make
2 - ./ex3 > ./asm/test.asm
3 - Tape 4+4
4 - CTRL+D
5 - Dans le dossier asm, asipro test.asm executable
6 - sipro executable
