#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int fd_src = 0;
    int fd_dst = 0; 
    int n = 0;
    char na_src[1024];
    char na_dst[1024];
    char buf[2048];

    if (3 != argc) 
    {
        printf("need more arguments\n");
        exit(1);
    }
    
    strcpy(na_src, argv[1]);
    strcpy(na_dst, argv[2]);
    
    fd_src = open(na_src,O_RDONLY);
    if (-1 == fd_src) 
    {
        perror("open file error:\n");
        exit(1);
    }

    fd_dst = open(na_dst,O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fd_dst < 0) 
    {
        perror("open file error:\n");
        exit(1);
    }

    while (n = read(fd_src,buf,1024)) 
    {
        write(fd_dst,buf,n);
    }

    return 0;
}

