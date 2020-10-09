#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int contains(char c,int size, char tab[]) {
	for (int i = 0; i < size; ++i)	{
		if (tab[i] == c) {
			return i;
		}
	}
	return -1;
}

int main(int argc, char const *argv[]){
	
	int cursor = 0;
	char lettres[256];

	int countLettres[256] ;


	int fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		printf("Erreur de fichier !\n"); 
		perror("File :");
	}

	char buffer[1024] ;
	int nbread;
	do	{
		nbread = read(fd, buffer, 1024) ;

		for (int i = 0; i < nbread; ++i) {
			
			int where = contains(buffer[i], 256, lettres); 
			//printf("%i\n", where);
			if (where == -1) {
				lettres[cursor] = buffer[i] ;
				countLettres[cursor] = 1;
				cursor++;

			}else {
				countLettres[where]++;

			}

		}


	} while (nbread == 1024);


	for (int i = 0; i < cursor; ++i)	{
		printf("%c : %i \n", lettres[i], countLettres[i]);
	}



	close(fd);
	return 0;
}

