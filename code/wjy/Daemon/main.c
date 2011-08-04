#include <stdio.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <unistd.h>

#include <stdlib.h>

#include <string.h>

int main(int argc, const char *argv[])
{
    int fd, i;
    pid_t pid;
    char *str = "this is a demon";
    
    pid = fork();
    if(pid < 0) 
    {
        printf("fork error\n");
        exit(1);
    }
    else if(pid > 0) 
    {
        exit(0); 
    }

    setsid();
    chdir("/");
    umask(0);

    for(i = 0; i < getdtablesize(); i++) 
    {
       close(i); 
    }

    while(1) 
    {
        if((fd = open("./temp.txt", O_CREAT|O_WRONLY|O_APPEND))>0) 
        {
            printf("open file error\n");
            return 4;
        }

        write(fd, str, strlen(str));
        close(fd);
        sleep(2);
    }

    return 0;
}
