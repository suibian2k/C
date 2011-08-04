#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8

int init(int *d, int n);
int print_array(int *d , int n);
int chang(int *d, int n);
int sort(int *d ,int n);

int main(int argc, const char *argv[])
{
    int d[N] = {2,6,3,5,4,1,7,0};

    //init(d,N);
    print_array(d,N);
    //chang(d,N);
    sort(d,N);
    print_array(d,N);

    return 0;
}

int init(int *d, int n)
{
    int i = 0;

    srand(time(NULL)); 
    for (i = 0; i < n; i++) 
    {
        d[i] = rand()%90 + 10;
    }
    return 0;
}

int chang(int *d, int n)
{
    int i = 0;
    int e = 0;
    int tmp = 0;

    e = n-1;
    while(1)
    {
        while (0 != d[i]%2) 
        {
            i++; 
        }
        
        while (0 == d[e]%2) 
        {
            e--;
        }

        if (i > e) 
        {
            return 0;
        }

        tmp = d[i];
        d[i] = d[e];
        d[e] = tmp;
    }
    return 0;

}
int print_array(int *d , int n)
{
    int i = 0;

    for (i = 0; i < n; i++) 
    {
        printf("%d\t",d[i]);
    }
    printf("\n");
    return 0;
}

int sort(int *d ,int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int tmp = 0;

    for (i = 1; i < n; i++) 
    {
        for (j = 0; j < i; j++) 
        {
            if ((0 == d[j]%2)&&(0 == d[i]%2)) 
            {
                if (d[i]<d[j]) 
                {
                    tmp = d[i];
                    for (k = i; k >j; k--) 
                    {
                        d[k] = d[k-1];
                    }
                    d[j] = tmp;
                   break;
                }
            }
            else if((0 == d[j]%2)&&(0 != d[i]%2))
            {
                    tmp = d[i];
                    for (k = i; k >j; k--) 
                    {
                        d[k] = d[k-1];
                    }
                    d[j] = tmp;
                   break;
            }
            else if((0 != d[j]%2)&&(0 != d[i]%2))
            {
                if (d[i]<d[j]) 
                {
                    tmp = d[i];
                    for (k = i; k >j; k--) 
                    {
                        d[k] = d[k-1];
                    }
                    d[j] = tmp;
                   break;
                }
            }
        }
        print_array(d,N);
    }
    return 0;
}
