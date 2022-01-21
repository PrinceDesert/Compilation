#include <stdio.h>
int main(void) {
	char *nom = NULL;
	if (nom != (void * ) 0) { // Nom défini
		printf("Bonjour % s!\n", nom);
	} else { // Nom indéfini
		fprintf(stderr, "nom indéfini ? oui !\n");
	}
	return 0;
}
