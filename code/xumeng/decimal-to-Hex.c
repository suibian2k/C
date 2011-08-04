#include <stdio.h>

int main(int argc, const char *argv[])
{
    
    
    int d = 0;
    int i = 0;
    unsigned  int mask = 0x0f;
    puts("number");
    scanf("%d", &d);
                
    puts("result:");
    char h[20] = "0123456789abcdef";
    int j = sizeof(int)*8-4;
    for (i = 0; i < sizeof(int)*2; i++,j-=4) 
    {
        printf("%c", h[(d>>j)&mask]);
    }
    printf("\n");
    return 0;
}
