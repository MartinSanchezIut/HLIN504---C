#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int recherche(char c, char buffer[], int debut, int fin) {
	for (int i = 0; i < fin; ++i)
	{
		printf("%c", buffer[i]);
		if (buffer[i] == c) {
			return i;
		}
	}
	return -1;
}

int main(int argc, char const *argv[]){
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		printf("Erreur de fichier !\n"); 
		perror("File :");
	}

	char c = argv[2][0] ;


	int size = lseek(fd, 0, SEEK_END) ;
	char buffer[size] ;

	int nbread = read(fd, buffer, size) ;

	int index = recherche(c, buffer, 0, size);

	printf("Le char %c est a l'index %i\n", c, index);


	return 0;
}