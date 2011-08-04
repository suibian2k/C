#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int fd,n;
    int pid;
    char buf[4096];
    fd = open("./hellp",O_RDWR);
    if(fd<0) 
    {
       perror("open error:");
       exit(1);
    }

    pid = fork();

    
    if(pid<0) 
    {
        perror("fork");
        exit(1);
    }
    // parent
    if(pid > 0) 
    {
        n = read(fd, buf, 4096);
        printf("read data is: %s",buf);
        //while(1);
    }
    //child
    else
    {
        n = write(fd,"hello word\n", 13);
        //while(1);
    }
    //n = read(fd, buf, 4096);
    //n = write(fd,"hello word\n", 13);

    if(n<0) 
    {
        perror("read error:");
        exit(1);
    }
    close(fd);
    return 0;
}
