#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    char sa[1024];
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    int i = 0;
    int n = 0;
    int rt = 0; 

    fp1 = fopen("text2", "r+");
    if (NULL == fp1) 
    {
        perror("fopen");
        exit(0);
    }
    
    fp2 = fopen("text3", "w+");
    if (NULL == fp2) 
    {
        perror("fopen");
        exit(0);
    }
    
    i = 0;
    n = 0;
    while (!feof(fp1)) 
    {
        n = fread(&sa[i],1,4,fp1);
        i += 4;
    }
    
    i = i - 4 + n;

    if (i != 0) 
    {
        sa[i] = '\0';
        fwrite(&sa[0],1,i,fp2);
    }

    return 0;
}
