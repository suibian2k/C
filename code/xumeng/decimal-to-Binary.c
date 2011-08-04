#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i = 0;
    int d = 0;
    int j = 0;
    unsigned int mask = 0x80000000;

    puts("need a number");
    scanf("%d", &d);

    puts("results:");
    
    for (i = 0; i < 32; i++) 
    {
        printf("%d", (d & mask) !=0 ? 1:0);
        mask >>= 1;
    }
    printf("\n");
    return 0;
}
