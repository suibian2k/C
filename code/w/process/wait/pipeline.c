#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAXLINE 80

int main(int argc, const char *argv[])
{
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];

    if(pipe(fd)<0) 
    {
        perror("pipe");
        exit(1);
    }
    if((pid = fork()) < 0) 
    {
        perror("fork");
        exit(1);
    }
    if(pid > 0) 
    {
        //close(fd[0]);
        write(fd[1], "hello world\n",13);

        //n = read(fd[0], line, MAXLINE);
        //write(STDOUT_FILENO, line,n);
        wait(NULL);
        exit(1);
    }
    else
    {
        //close(fd[1]);
        printf("dd:wq\n");
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line,n);
        exit(1);
        printf("dd\n");
    }
    usleep(1);
    return 0;
}
