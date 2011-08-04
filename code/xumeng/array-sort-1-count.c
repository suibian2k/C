#include <stdio.h>
#define N 10

int sort(unsigned int *a, int len);
int get_length(int d);
void print_array(int *d, int len);

int main(int argc, const char *argv[])
{
    int d[N] = {0,1,2,3,4,5,6,7,8,9}; 
    sort(d, N);
    print_array(d,N);
    return 0;
}

int sort(unsigned int *a, int len)
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    int tmp2 = 0;

    for (i = 0; i < len-1; i++) 
    {
        tmp = i; 
        for (j = i+1; j < len; j++) 
        {
            if (get_length(a[tmp])>get_length(a[j])) 
            {
                tmp = j;
            }
            else if (get_length(a[tmp]) == get_length(a[j])) 
            {
               if (a[tmp] > a[j]) 
               {
                   tmp =j;
               }
            }
        }
        tmp2 = a[i];
        a[i] = a[tmp];
        a[tmp] = tmp2;
    }
    return 0;
}

int get_length(int d)
{
    int count = 0;
    int i = 0;
    
    for (i = 31; i >=  0; i--) 
    {
        if ((d&(0x01<<i)) > 0) 
        {
            count++;
        }
    }
    return count;
}

void print_array(int *d, int len)
{
    int i = 0;
    for (i = 0; i < len; i++) 
    {
        printf("%d\t%d\n", d[i],get_length(d[i]));

    }
    printf("\n");
}
