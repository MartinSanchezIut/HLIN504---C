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
 
  s.sa_handler = signal_handler; 
 
  int retval = sigaction(SIGSEGV, &s, NULL); 
  if(retval<0) { 
    perror("sigaction failed"); 
    abort(); 
  } 
 
  *(int*)0 = 0;
 
  return 0; 
}