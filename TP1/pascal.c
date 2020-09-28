#include <stdio.h>
#include <stdlib.h>

int main (int argc , char *argv[]) {
    
    int taille = 50;
    int longueur = 1;

    int** t = (int**) malloc(taille*sizeof(int*));
    for ( int i = 0; i < taille ; i++ ) {

        t[i] = (int*) malloc(longueur*sizeof(int));

        for ( int j = 0 ; j < longueur ; j++ ) {
            if ( j == 0 || j == longueur-1 ) {
                t[i][j] = 1;

            }

            else {
                t[i][j] = t[i-1][j]+t[i-1][j-1];
            }

            printf("%i ", t[i][j]);

        }
        printf("\n");




        longueur++;
    }
}