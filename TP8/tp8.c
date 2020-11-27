#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

void crible(int *in) {
	int ecrire = 1;
	int lire = 0;

	close(in[ecrire]) ;
	int P;


	if (sizeof(int) != read(in[lire], (void *) &P, sizeof(int))) {
		close(in[lire]);
		return;
	}
	printf("%d ", P);
	fflush(stdout);

	int out[2];
	pid_t fils;
	if (pipe(out) == -1) {
		perror("Pipe error");
	}

	switch (fils = fork()) {
		case -1:
			perror("Fork issues");
			exit(2);
			break;

		case 0: // FILS
			close(in[lire]);
			crible(out);
			exit(0);
			break;
		default: // PERE
			close(out[lire]);

			int i;
			while(read(in[lire], &i, sizeof(int))) {
				if (i % P != 0) {
					write(out[ecrire], (void *) &i, sizeof(int));
				}
			}
			close(in[lire]);
			close(out[ecrire]);
			wait(0);
			exit(0);
			break;
	}
}

int main(int argc, char**argv) { 
 		// Size of a pipe  65000 octets
/*
	int block = 1024;

	int tube[2];
	pipe(tube);

	int cumul = 0;
	char s[block];

	while(1) { // INFINIE
		write(tube[1], s , block);
		cumul += block;
		printf("%d octets \n", cumul);
	}
*/
	int borne = 1700;

	int in[2];
	pid_t fils;


	if (pipe(in) == -1) {
		perror("Pipe probleme") ;
		exit(1);
	}

	switch (fils = fork()){
		case -1:
			perror("Fork issues");
			exit(2);
			break;
		case 0: // FILS
			crible(in);
			exit(0);
			break;
		default:
			close(in[0]);
			for (int i = 2; i <= borne; ++i){
				write(in[1], (void *) &i, sizeof(int));
			}
			close(in[1]);
			wait(0);
			return 0;
			break;
	}

/*
	char c;
	if(pipe(tube))	{
		perror("probleme de creation du tube\n");exit(-1);
	}
	

	switch (fork())	{

		case -1: {
			perror("probleme de fork \n");
			exit(-2);
		}

		case 0:{
			close(tube[1]);					 //le fils n'ecrit pas
			while(read(tube[0],&c,1)) 
				printf("le caractere lu est: %c \n",c);
			write(1,&c,1);
			exit(0);
		}

		default: {
			int cr;
			close(tube[0]); 				//le pere ne lit pas dans le tube
			while((c=getchar())!=EOF){
				if((c<='z')&&(c>='a')){
					write(tube[1],&c,1); 	//ecriture dans le tube
				}
			}
			close(tube[1]); //fermeture du tube en ecriture
			wait(&cr); //attente de la fin du fils
		}
	}
*/
	return 0; 
}