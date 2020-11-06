#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]){



	/* 
	int n = atoi(argv[1]) ;
	for (int i = 0; i < log2(n); ++i)
	{
		pid_t pid;
		switch ( pid = fork()) {
		case -1:
			printf("Erreur dans le fork ! \n");
			break; 
		case 0:
			// Enfant
			printf("Je suis l'enfant et n = %i \n", n);
			break;
		default: 
			// Parent
			printf("Je suis le père et n = %i \n", n);
			break;
		}
	}
	*/


	/*  
	pid_t pid = getpid() ;
	printf("Le texte : %i\n", pid);
	execl("./test", "test", 	NULL);
	*/

	/* Recouvrement 
	char command[50];

 	strcpy(command, "ls -l ./");
   	system(command);

	printf("Petit texte\n");
	execl("/bin/ls", "ls", "-l", "/bin/", NULL);
	execlp("gcc", "gcc", "tp4.c", NULL) ;
	*/

	/*  Template de fork
	int n = 4 ;
	pid_t pid;
	switch ( pid = fork()) {
		case -1:
			printf("Erreur dans le fork ! \n");
			break; 
		case 0:
			// Enfant
			n = 2;
			printf("Je suis l'enfant et n = %i \n", n);
			break;
		default: 
			// Parent
			printf("Je suis le père et n = %i \n", n);
			break;
	}
	*/

	/*
	for (int i = 0; i < 4; ++i)	{
		pid_t nPid ;
		if ( (nPid = fork()) == 0) {
			printf("un nouveau descendant %d  de parent %d ! i=%d\n",getpid(), getppid(),i);
		}else {
			int status ;
			wait(&status);
		}
	}
	*/
	return 0;
}