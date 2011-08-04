#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 10

void array_print(int *p, int m, int n);
void array_init(int *p, int m ,int n);
void array_sort(int *p, int m, int n);

int main(int argc, const char *argv[])
{
    int array[M][N];
    array_init(array[0], M, N);
    array_sort(array[0], M, N);
    array_print(array[0], M, N);

    return 0;
}

void array_init(int *p, int m ,int n)
{

   int i = 0;

   srand(time(NULL));
   for (i = 0; i < m*n; i++) 
   {
       *(p+i) = rand()%200;
   }
}
void array_print(int *p, int m, int n)
{
   int i = 0;

   for (i = 0; i < m*n; i++)
   {
        if (i%10 == 0) 
        {
            printf("\n");
        }
        printf("%5d",*(p+i));
   }

   printf("\n");
    
}

void array_sort(int *p, int m, int n)
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    int t = 0;

    for (i = 0; i < m*n; i++) 
    {
        t = i;
        for (j = i+1; j < m*n; j++) 
        {
            
            if(*(p+i)> *(p+j))
            {
                t = j;
            }
            
        }
        printf("i=%5d, j=%5d ",*(p+i),*(p+j));
        if (t != i) 
        {
            tmp = *(p+i);
            *(p+i) = *(p+t);
            *(p+t)  = tmp;

        }
        printf("i=%5d\n", *(p+i));
    }

}
