#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    char str [100];
    int number = 0;
    int base = 0;

    char *p;
    printf("number:\n");
    scanf("%s", str);
    printf("base\n");
    scanf("%d", &base);

    number = strtol(str,&p,base);
    printf("decimal number:%d\n", number);
    printf("%c\n", *p);
    return 0;
}
