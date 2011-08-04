#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define N 10

int main(int argc, const char *argv[])
{
    short buf[N];
    int kb_fd;
    int i;

    kb_fd = open("/dev/console",O_RDONLY);
    if (-1 == kb_fd) 
    {
        perror("open error"); 
        exit(1);
    }
    while (1) 
    {

        write(kb_fd, buf, N);
        for (i = 0; i < 10; i++) 
        {
            printf("%o\n",buf[i]);
        }
    }    
    close(kb_fd);
    return 0;
}
