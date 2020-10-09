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


	for (int i = 0; i < size * 16; i=i+16)	{
		
		printf("%8.8x : %i \n", i, 'a');
	}




	return 0;
}