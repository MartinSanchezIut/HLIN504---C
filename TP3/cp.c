#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[]){
	
	int source = open(argv[1], O_RDONLY);
	int destination = open(argv[2],  O_WRONLY | O_CREAT, 0666);
	if ((source < 0) | (destination < 0)) {
		printf("Erreur de fichier !\n"); 
		perror("File :");
	}

	char buffer[1024] ;
	int nbRead;
	do{
		nbRead = read(source, buffer, 1024) ;
		//printf("%i\n", nbRead);
		write(destination, buffer, nbRead) ;


	} while (nbRead > 1024);


	


	return 0;
}