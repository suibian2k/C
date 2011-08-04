#include <stdio.h>
#include <strings.h>

void flush_stdin(void)
{
    int c;
    while(((c = getchar()) != '\n')&&(EOF != c));
}

char *get_str(char *str, int len)
{
    char *head = str;
    bzero(str, len); 

    while('\n' != (*str = getc(stdin))) 
    {
        str++; 
    }
    *(str) = '\0';

    return head; 
}
