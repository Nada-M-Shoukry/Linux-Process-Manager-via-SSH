#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
    pid_t PID1, PID2;

    //WORKER1: (mpstat) 
    PID1 = fork();
    if (PID1 == 0)
    {
        printf("Worker1: Starting mpstat to monitor CPU...\n" );
        char* argv[] = {"/usr/bin/mpstat", NULL};
        execv(argv[0], argv);

        //Only runs if execv fails
        exit(1);
    }

    //WORKER2: (ps) 
    PID2 = fork();
    if (PID2 == 0)
    {
        printf("Worker2: Starting ps to monitor Processes...\n" );
        
        //Argument: Path to binary, flags, NULL
        char* argv[] = {"/usr/bin/ps","-A", NULL};
        execv(argv[0], argv);

        //Only runs if execv fails
        exit(1);
    }

    //Parent process
    if( PID1 > 0 && PID2 > 0)
    {
        printf("Parent: Waiting for children to report back...\n\n");

        //Waiting for children to finish (prevent zombie processes)
        wait(NULL);
        wait(NULL);

        printf("\nParent: All worker tasks are displayed above. Mission complete.\n");
    }
}