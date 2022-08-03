//process creation
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    int pid,pid1,pid2;
    pid = fork();
    if(pid==-1)
    {
        printf("there was an error while the creation of process\n");
        exit(0);
    }
    if(pid!=0)
    {
        pid1 = getpid();
        printf("parent process id : %d \n",pid1);
    }
    else
    {
        pid2 = getpid();
        printf("child process id : %d \n",pid2);
    }
    return 0;
}

