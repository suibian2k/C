#include <stdio.h> 
#include <string.h>

int  my_strcmp(char *dest, char (*src)[10], int num);
int main(int argc, const char *argv[])
{
    char name [5][10];
    char tmp[10];
    int i;
    int j;
    int flag;

    for (i = 0; i < 5; i++) 
    {
        printf("please input a name:\n");
        fgets(tmp, 10, stdin);

        if (0 != my_strcmp(tmp,name,5)) 
        {
            strcpy(name[i],tmp);
        }
        else 
        {
            i--;
        }
    }
    for (i = 0; i < 5; i++) 
    {
        printf("%d\t%s\n",i,name[i]);
    }
    return 0;
}

int  my_strcmp(char *dest, char (*src)[10],int num)
{
    int  i = 0;
    int flag = 0;

    if (0 == num) 
    {
        return -1;
    }
    for (i = 0; i < num; i++) 
    {
        flag = strcmp(dest,src[i]);
        if(0 == flag)
        {
            printf("error\n");
            return 0;
        }
    }
    return 1;
}
