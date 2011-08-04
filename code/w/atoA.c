#include <stdio.h>
#include <string.h>

int atoA(char *s);
int main(int argc, const char *argv[])
{
    char s[4096] = "abcdEF";
    atoA(s);
    printf("%s\n",s);

    return 0;
}

int atoA(char *s)
{
    int i = 0;
    for (i = 0; i < strlen(s); i++) 
    {
        if ((s[i]>96)&&(s[i]<123)) 
        {
           s[i] -= 32;
        }
    }

    return 0;
}

