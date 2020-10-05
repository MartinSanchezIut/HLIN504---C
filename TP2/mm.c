#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define TAILLE 4

typedef struct mm* mm ;

struct mm
{
	char secret[TAILLE+1] ;
	int nbEssai ;
};



mm mm_creer() {
	mm jeu = malloc(sizeof(TAILLE+1) + sizeof(int)) ;

	for (int i = 0; i < TAILLE ; ++i)
	{
		//jeu*+i =   '2' ; //rand() % 10;
	}

	return jeu;
}




void mm_detruire(mm* mm) {
	free(mm) ;
}

