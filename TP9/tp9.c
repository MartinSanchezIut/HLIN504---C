#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>


void *crible(void *arg){

    int *in = (int *)arg;
    int p;
    if (read(in[0], &p, sizeof(int)) != sizeof(int))
    {
        close(in[0]);
        exit(0);
    }

    printf("%d ", p);

    int out[2];

    if (pipe(out) == -1)
    {
        perror("Probleme de pipe");
        exit(1);
    }

    pthread_t tid;
    int s = pthread_create(&tid, NULL, crible, &out);

    if (s != 0)
    {
        printf("création impossible du thread \n");
        exit(4);
    }
    int i;
    while (read(in[0], &i, sizeof(int)) == sizeof(int))
    {
        if (i % p)
        {
            write(out[1], &i, sizeof(int));
        }
    }

    close(in[0]);
    close(out[1]);
    pthread_join(tid, NULL);
    printf("JOIN");
    exit(0);
}

int main(int argc, char *argv[]){
    int borne = 100;
 
    int tube[2];
    if (pipe(tube) == -1)
    {
        perror("Problème de pipe");
        exit(1);
    }
 
    pthread_t fils;
    if (pthread_create(&fils, NULL, crible, &tube))
    {
 
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    for (int i = 2; i <= borne; ++i)
    {
        write(tube[1], (void *)&i, sizeof(int));
    }
    close(tube[1]);
 	
    void *res;
    pthread_join(fils, &res);


    printf("\n");
    return 0;
}