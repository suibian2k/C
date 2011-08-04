#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    FILE *fp = fopen("text2", "r+");
    int c;
    int i;
    //if(EOF == (c = fgetc(fp)))
    //if(EOF == fscanf(fp," %d",&c))
    //printf("ddddd\n");

    for (i = 0; i < 10; i++) 
    {
        
        //c = fgetc(fp);
        fscanf(fp,"%d",&c);
    printf("c = %c\n",c );
    }
    return 0;
}
