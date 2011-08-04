#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int fd, i;
    char *p = NULL;

    fd = open("1.txt", O_RDWR);
    if(fd<0) 
    {
        perror("open file error"); 
        exit(1);
    }
    

    p = (char *)mmap(NULL, 10, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    
    if (MAP_FAILED == p) 
    {
        perror("mmap fiel 1.txt error"); 
        exit(1);
    }

    close(fd);

    for (i = 0; i < 10; i++) 
    {
        printf("p[%d]=%d ", i , p[i]);
    }
    
    printf("\n");
    
    getchar();

    munmap(p, 10); 

    return 0;
}
