#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[]){
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		printf("Erreur de fichier !\n"); 
		perror("File :");
	}

	int size = lseek(fd, 0, SEEK_END) ;

	int bla = 0;

	char buffer[1024] ;
	int nbread;
	do	{
		nbread = read(fd, buffer, 1024) ;

		printf("%8.8x %i :", bla);
		for (int i = 0; i < nbread; ++i) {
			printf("%c ", buffer[i]);
		}
		printf("\n");

		bla++;


	} while (nbread == 1024);

	return 0;
}