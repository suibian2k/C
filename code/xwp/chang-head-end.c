#include <stdio.h>
#define N 6

int  changHE(int *d, int n);
void print(int *d,int n);

int main(int argc, const char *argv[])
{
    int d[4096] = {1,2,3,4,5,6};
    print(d,N);
    changHE(d,N);
    print(d,N);

    return 0;
}

int changHE(int *d, int n)
{
    if ((NULL==d)||(n<=0)) 
    {
        return -1;
    }
    if (1 == n) 
    {
        return 0;
    }

    int i = 0;
    int tmp = 0;
    int add = n/2;

    for (i = 0; i < add; i++) 
    {
        tmp = d[i];
        d[i] = d[i+add+n%2];
        d[i+add+n%2] = tmp;
    }

    return 0;
}

void print(int *d,int n)
{
    int i = 0;
    for (i = 0; i < n; i++) 
    {
        printf("%d", d[i]);
    }
    printf("\n");
}
