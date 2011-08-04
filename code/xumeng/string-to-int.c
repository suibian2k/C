#include <stdio.h>
#include <string.h>
int my_stoi(char *s);
int main(int argc, const char *argv[])
{
    char s[4096] = "234";
    printf("%s\n",s);
    printf("%d\n",my_stoi(s));
    return 0;
}

int my_stoi(char *s)
{

    int i = 0;
    int j = 0;
    int rt = 0;
    int count = strlen(s);
    int tmp = 0;

    for (i = 0; i < count; i++) 
    {
        tmp = (int)(s[i] - 48);
        for (j = i; j < count -1 ; j++) 
        {
            tmp = tmp*10;
        }
        rt += tmp;
    }

    return rt;
}
char *my_itos(int d)
{
    
    int i = 0;
    int count = 0;
    while (0 == d) 
    {
        d = d - d%pow(10,0-count);
        count++;
    }

    char * s = malloc(sizeof(char)*count+1);
    for (i = 0; i < count; i++) 
    {
        *s = d - d%pow(10,0-(count-i-1));
        d -= *s;
        s++;
    }
    *s = '\0';

    return s;
}
