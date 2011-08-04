#include <stdio.h>

int main(int argc, const char *argv[])
{
    int array[100];

    init_array(array, 100);
    
    print_array(array, 100);
    return 0;
}

int init_array(int p[], int n)
{
    int i = 0;
    do 
    {
        p[i] = i + 1;
        i++;
    } while (i<n);
    return 0;
}

int print_array(int p[] , int n)
{
    int i = 0;
    do 
    {
        printf("%5d", p[i]);
        i++;
    } while (i<n);

    printf("\n");
    return 0;
}
