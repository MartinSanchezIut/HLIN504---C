#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

void recursiv(char* path, int prefix) {
    struct dirent *dirent;
    DIR *dir;
    
    for (int i = 0; i < prefix; ++i){
    	printf(" ");
    }
    printf("%s \n", path);

	dir=opendir(path);
    if (dir != NULL) {

    	while ((dirent = readdir(dir)) != NULL) {
    		if (strncmp(dirent->d_name, "..", 2)) {
    			if (strncmp(dirent->d_name, ".", 1)) {
    				recursiv(dirent->d_name, prefix +4);
    				//printf("Printable %s\n", dirent->d_name);
    			}
    		}
    		/*
    		if (dirent->d_name != "." && dirent->d_name != "..") {

    			printf("Printable %s\n", dirent->d_name);
    			//recursiv(dirent->d_name, prefix +1);
    		}
			*/
    	}

	}
}

int main(int argc, char const *argv[]){
	recursiv(".", 0);
        
}