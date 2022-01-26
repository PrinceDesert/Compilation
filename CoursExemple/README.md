Au préalable installation de la bibliothèque libbison(pour par exemple l'option -ly) : sudo apt install libbison-dev
https://packages.debian.org/buster/libbison-dev

Compilation et éxécution avec Makefile : make expr2

Compilation et éxécution à la main :

Avec l'option -d, bison génère, en plus de expr2.tab.c, un fichier expr2.tab.h contenant entre autres les définitions C pour les tokens (terminaux) qu'il utilise

```
bison -d expr2.y
flex -D_POSIX_SOURCE -DYY_NO_INPUT --nounput expr2.l
gcc -std=c11 -pedantic -Wall expr2.tab.c -c
gcc -std=c11 -pedantic -Wall lex.yy.c -c
```

L'option -ly permet d'utiliser le main de la bibliothèque bison
Attention : pas le même comportement que le main par défaut de flex
gcc expr2.tab.o lex.yy.o -ly

