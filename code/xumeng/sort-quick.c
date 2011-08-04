#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int p[], int n);
void init_array(int p[], int n);
void bubble_array(int p[], int n);
void quick_sort(int p[], int x, int y);

#define N   10

int main(int argc, const char *argv[])
{
    int array[N];

    init_array(array, N);
//    bubble_array(array, N);
    quick_sort(array, 0, N-1);
    print_array(array, N);

    return 0;
}

void init_array(int p[], int n)
{
    int i = 0;
    
    srand(time(NULL));
    for (i = 0; i < n; i++) 
    {
        p[i] = rand()%200;
    }
}

void print_array(int p[], int n)
{
   int i = 0;

   for (i = 0; i < n; i++) 
   {
        if((i%10) ==0) 
        {
            printf("\n");
        }
        printf("%5d", p[i]);
   }
   printf("\n");
}

void bubble_array(int p[], int n)
{
    int i = 0;
    int j = 0;
    int temp = 0;

    for (i = 0; i < n-1; i++) 
    {
        for (j = i+1; j < n; j++) 
        {
            if(p[i] > p[j]) 
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void quick_sort(int p[], int x, int y)
{
    int i = x;
    int j = y;
    int mid = p[(x+y)/2];
    int temp = 0;

    while (i <= j) 
    {
        while(p[i] < mid) i++;
        while(p[j] > mid) j--;

        if (i <= j) 
        {
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;

            i++;
            j--;
        }
    }

    if (x < j) 
    {
        quick_sort(p,x,j);
    }
    if (i < y) 
    {
        quick_sort(p,i,y);
    }
}
