#include <stdio.h>
#include <stdlib.h>
void print_array(int *p);
void init_array(int *p);
void sort_array(int *p);

int main(int argc, const char *argv[])
{
    int array[N];

    init_array(array);
    sort_array(array);
    print_array(array);

    return 0;
}

void print_array(int *p)
{
    int * ptr;
    ptr = p;
        for (; ptr < p + N; ptr++) 
        {
            printf("%d\n", *ptr);        
            
        }
}
void init_array(int *p)
{
    int i = 0;
    srand(time(NULL));
    for (i = 0; i < N; i++) 
    {
        p[i] = (rand()%20);
    }
}

void sort_array(int *p)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < N-1; i++) 
    {
        if (p[i] > 0) 
        {
            for (j = i+1; j < N; j++) 
            {
                if (p[j] = p[i]) 
                {
                    p[j] = -1;
                }
            }
        }
    }
