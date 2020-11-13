#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <ucontext.h>
#include <errno.h>


struct sigaction s; 


/* Function to call upon signal reception */ 
void signal_handler(int signo) { 
  printf("Segmentation faul chai \n"); 

  exit(1);
} 


int main(int argc, char**argv) { 
 
  pid_t pid;
  switch ( pid = fork()) {
    case -1:
      printf("Erreur dans le fork ! \n");
      break; 
    

    case 0:
      // Enfant 1
      printf("Je suis l'enfant et n = %i \n", n);
      break;
    

    default: 
      // Parent

      pid_t pid2;
      switch ( pid2 = fork()) {
        case -1:
          printf("Erreur dans le fork ! \n");
          break;

        case 0:
          // Enfant 2
          printf("Je suis l'enfant et n = %i \n", n);
          break;
        

        default: 
          // Parent
          printf("Je suis le père et n = %i \n", n);

          s.sa_handler = signal_handler; 

          int retval = sigaction(SIGCHLD, &s, NULL); 
          if(retval<0) { 
            perror("sigaction failed"); 
            abort(); 
          } 

          
          break;
      }
      break;
  }
  return 0; 
}