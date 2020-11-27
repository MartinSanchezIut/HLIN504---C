#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h> 



int main(int argc, char**argv) { 

    int online = 1;
    char arr1[256], arr2[256]; 


	int fd2 ;
	int fd ;
	switch (fork())	{
		case -1: {
			perror("probleme de fork \n");
			exit(-2);
		}

		case 0:{  // COTE ECRITURE
			if (fd2 = open("monFIFO2", O_WRONLY) == -1) {
				perror("Open error");
				exit(1);
			} 

			while(online) {
				fgets(arr2, 256, stdin); 

				if (strncmp("exit", arr2, 5) == 0) {
					online = 0;

				}else {
				    write(fd2, arr2, strlen(arr2)+1); 
				}
			}


			break;
		}

		default: {
			int fd ;
			if (fd = open("monFIFO", O_RDONLY) == -1) {
				perror("Open error");
				exit(1);
			} 			

			while(online) {
					read(fd, arr1, sizeof(arr1)); 
					printf("%s\n", arr1);
				
			}


			break;
		}
	}
	return 0; 
}