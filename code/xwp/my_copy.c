#include <stdio.h>

int my_copy(const char *fn1, const char *fn2);

int main(int argc, const char *argv[])
{
    my_copy(argv[1],argv[2]);
    return 0;
}

int my_copy(const char *fn1, const char *fn2)
{
    FILE *fps = NULL;
    FILE *fpd = NULL;
    int size = 0;
    char buf[4096];

    fps = fopen(fn1,"rb");

    if (NULL == fps) 
    {
        perror("open to r");
        return -1;
    }

    fpd = fopen(fn2,"wb");

    if (NULL == fpd)
    {
        perror("open to w"); 
        return -1;
    }

    do 
    {
        size = fread(buf,1,4096,fps);

        if (0 != ferror(fps)) 
        {
            perror("read");
            return -1;
        }

        fwrite(buf,1,size,fpd);

        if (0 != feof(fps)) 
        {
            printf("sucess\n");
            break; 
        }

    } while (1);

    fclose(fps);
    fclose(fpd);
    return 0;
}
