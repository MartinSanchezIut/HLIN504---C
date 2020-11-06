#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]){
	char* fd = argv[1];
	struct stat buf;          

	stat(fd, &buf);
	if (S_ISREG(buf.st_mode)) {
		printf("C'est un fichier normal\n");
	}else if (S_ISDIR(buf.st_mode)) {
		printf("C'est un répertoire\n");
	}else if (S_ISCHR(buf.st_mode)) {
		printf("C'est un un périphérique en mode caractère\n");
	}else if (S_ISBLK(buf.st_mode)) {
		printf("C'est un un périphérique en mode block\n");
	}else if (S_ISFIFO(buf.st_mode)) {
		printf("C'est un un FIFO\n");
	}else if (S_ISLNK(buf.st_mode)) {
		printf("C'est un un lien symbolique\n");
	}else if (S_ISSOCK(buf.st_mode)) {
		printf("C'est un un socket\n");
	}else {
		printf("Un petit souci\n");
	}
}