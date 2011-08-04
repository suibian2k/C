#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
 
int main(int argc, const char *argv[])
{
    char *sp, *dp;
    int sfd, dfd;
    int len;
    struct stat sst; 

    sfd = open("src.txt",O_RDONLY);
    
    //get file length
    fstat(sfd, &sst);
    len = sst.st_size;

    sp = mmap(NULL, len, PROT_READ, MAP_SHARED, sfd, 0);
    if (MAP_FAILED == sp) 
    {
        perror("mmap sp");
        exit(1);
    }
    
    dfd = open("dst.txt",O_RDWR|O_CREAT, 0644);


    
    //make big
    lseek(dfd, len-1,SEEK_SET);
    write(dfd,"",1);

    dp = mmap(NULL, len, PROT_WRITE, MAP_SHARED, dfd, 0);
    
    if (MAP_FAILED == dp) 
    {
        perror("mmap dp");
        exit(1);
    }

    memcpy(dp, sp, len);
    
    close(sfd);
    close(dfd);

    munmap(sp, len);
    munmap(dp, len);

    return 0;
}
