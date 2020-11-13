#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>



struct sigaction s; 


/* Function to call upon signal reception */ 
void signal_handler(int signo) { 
  printf("Received: signal %d\n", signo); 

  // Après l'avoir capturé une fois, je remet le comportement par defaut.
  s.sa_handler = SIG_DFL; 
  sigaction(signo, &s, NULL); 
} 
 


int main(int argc, char**argv) { 
  if(argc != 2) { 
    fprintf(stderr, "usage: %s signo\n", argv[0]); 
    return 1; 
  } 
 
  /* Initialize the sigaction structure */ 
  int signo = atoi(argv[1]); 
  s.sa_handler = signal_handler; 
 
  /* Install the signal handler */ 
  printf("Installing signal handler for signal %d\n", signo); 
  int retval = sigaction(signo, &s, NULL); 
  if(retval<0) { 
    perror("sigaction failed"); 
    abort(); 
  } 
 
  /* Wait to receive signals */ 
  while(1) { 
    printf("[%d] Sleeping...\n", getpid()); 
    sleep(1); 
  } 
 
  return 0; 
}