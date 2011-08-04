#include <stdio.h>
#include <stdlib.h>

#define N 5

struct wyp
{
    int a;
    int count;
}; 

int sort_bit(int *d, struct wyp *sd, int n);
int get_bit(int a);
void print_s(struct wyp *sd, int n);

int main(int argc, const char *argv[])
{
    int d [N] = {1,2,3,4,5};
    struct wyp sd [N];
    sort_bit(d ,sd ,N);

    print_s(sd,N);
    return 0;
}

int sort_bit(int *d, struct wyp *sd, int n)
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    int tj = 0;

    for (i = 0; i < n; i++) 
    {
        sd[i].a = d[i];
        sd[i].count = get_bit(d[i]);
    }

    for (i = 0; i < n - 1; i++) 
    {
        tj = i;   
        for (j = i + 1; j < n; j++) 
        {
            if (sd[tj].count>sd[j].count) 
            {
                tj = j;
            }
        }
        if (tj != i) 
        {
            tmp = sd[tj].a;
            sd[tj].a = sd[i].a;
            sd[i].a = tmp;

            tmp = sd[tj].count;
            sd[tj].count = sd[i].count;
            sd[i].count = tmp;

        }
    }

    return 0;
}

int get_bit(int a)
{
    int count = 0;
    int i = 0;
    if (a<0) 
    {
        count++;
        a = a&0x7888;
    }
    for (i = 0; i < 32; i++) 
    {
        if(0 != ((a>>i)&0x01))
        {
            count++;
        }
    }
    return count;
}

void print_s(struct wyp *sd, int n)
{
    int i = 0;
    for (i = 0; i < n; i++) 
    {
        printf("%d\t",sd[i].a);
    }
    printf("\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t",sd[i].count);
    }
    printf("\n");
}
