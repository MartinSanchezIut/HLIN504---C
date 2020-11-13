#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>



struct sigaction s; 
int reussi =1;

/* Function to call upon signal reception */ 
void signal_handler(int signo) { 
  static int cnt = 0;

  if (cnt == 0) {
    printf("Encore une chance !\n");
    cnt++;
    alarm(2);
      scanf("Val ");

  }else {
     printf("Trop tard !"); 
    reussi =0;
  }
} 
 


int main(int argc, char**argv) { 

  //unsigned int x = alarm(sec);
 
  s.sa_handler = signal_handler; 
  int retval = sigaction(SIGALRM, &s, NULL); 

  if(retval<0) { 
    perror("sigaction failed"); 
    abort(); 
  } 
 
  printf("Entrez uen valeur avant 10s\n");
  alarm(3);
  scanf("Val ");
  alarm(0);

  
  if (reussi != 0) 
    printf("reussi\n");

  return 0; 
}