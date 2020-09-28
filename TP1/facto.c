#include <stdio.h>
#include <stdlib.h>

unsigned long factorielle(unsigned long x) {
	if ( x == 1 ) {
		//printf("Retourne 1\n");
		return 1;
	}
	else {
		printf("Retourne %li\n", x);
		return x*factorielle(x-1);
	}
}


int main (int argc , char *argv[]) {
	unsigned long facto = factorielle(50000000000);

	printf("%lu\n", facto );
}