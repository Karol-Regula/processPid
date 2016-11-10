#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

void sigHandler(int);

void main(){

    signal(SIGINT, sigHandler);
    signal(SIGUSR1, sigHandler);

    while(1){
	printf("My PID: %d\n", getpid());

	sleep(1);
    } 
}


void sigHandler(int signal)
{
    if (signal == SIGINT){
        int file = open("log.txt", O_CREAT|O_APPEND, 0644);
        char a[] = "Exited due to signal: SIGINT\n";
        write(file, a, sizeof(a));
        close(file);
        exit(0);
    }
    if (signal == SIGUSR1){
	printf("Parent PID: %d\n", getppid());
    }
}
