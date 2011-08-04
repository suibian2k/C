#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    int status;
    pid_t pid = fork();
    if(pid<0) 
    {
        perror("fork");
        fork();
        exit(1);
    }
    if(pid>0) 
    {
        printf("parent\n");
        printf("id = \t%d\n",getppid());
        kill(pid,SIGKILL);
        wait(&status);
        printf("wait = \t%d\n", wait(&status));
        printf("WIFEXITED = \t%d\n",WIFEXITED(status));
        printf("WEXITSTATUS = \t%d\n", WEXITSTATUS(status));
        printf("WTERMSIG = \t%d\n", WTERMSIG(status));
        while(1);
    }
    else
    {
        printf("child\n");
        printf("id = \t%d\n",getpid());
    }
    //wait(&status);

    usleep(1);
    return 2;
}
