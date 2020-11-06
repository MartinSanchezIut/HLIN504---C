#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(int argc, char const *argv[]){
	int continuer = 1;
	char endShell[] = "quit";
	
	char buffer[256];
	printf("=*=*=*=*=*= Mon  Shell =*=*=*=*=*=\n");
	do{

		int nbRead = read(0, buffer , 256) ;

		char *command[] ;

		for (int i = 0; i < nbRead; ++i){
			command[i] = buffer[i] ;
		}
		command[nbRead] = NULL;
		
		execvp(command[0] , command);

		/*
		pid_t pid;
		int status;

		switch ( pid = fork()) {
		case -1:
			printf("Erreur dans le fork ! \n");
			exit(1);
			break; 
		case 0:
			// Enfant
			execlp(command, command, NULL);
			break;
		default: 
			wait(&status) ;
			break;
		}
		*/

		if (strncmp(endShell, command, 4) == 0) {
			continuer = 0;
		}
	} while (continuer);

	printf("=*=*=*=*=*= Au Revoir =*=*=*=*=*=\n");
	return 0;
}

