#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int fd, i;
    char *p = NULL;

    fd = open("1.txt", O_RDWR|O_CREAT|O_TRUNC, 0644);
    if(fd<0) 
    {
        perror("open file error"); 
        exit(1);
    }
    
    //file size is 6
    lseek(fd, 5, SEEK_SET);
    write(fd, "", 1);

    p = (char *)mmap(NULL, 10, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    
    if (MAP_FAILED == p) 
    {
        perror("mmap fiel 1.txt error"); 
        exit(1);
    }

    close(fd);

    for (i = 0; i < 10; i++) 
    {
        p[i] = (int)i;
    }

    
    printf("shared memory init ok!\n");

    //getchar();

    munmap(p, 10); 

    return 0;
}
