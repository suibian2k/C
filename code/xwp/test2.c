#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a;
    int *p;
    p = &a;
    *p = 0x500;
    a= (int)(*(&p));
    if (a == (int)p) 
    {
        printf("1\n");
    }
    printf("%d\n",*p);
    a = (int)(&(*p));
    if (a == (int)p) 
    {
        printf("1\n");
    }
    
    return 0;
}
