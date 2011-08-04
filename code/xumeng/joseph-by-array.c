#include <stdio.h>
#include <string.h>
void killPeople(char *name, int num);

#define N  10
int main(int argc, const char *argv[])
{
    char name[N];
    int i = 0;
    for (i = 0; i < N; i++) 
    {
        name[i] = 1;
    }

    int num = N;
    
    killPeople(name, num);
    return 0;
}

void killPeople(char *name, int num)
{
    int i = 0;
    int interval = 5;
    int out_counter = 0;
    int out_total = 0;

    while (out_total < num -1) 
    {
        if (name[i] != 0) 
        {
            
            out_counter++;
            if (out_counter == interval) 
            {
                out_counter = 0;
                name[i] = 0;
                out_total++;
                printf("%5d(out)\n", i+1);
            }
            else
            {
                printf("%5d", i+1);
            }


        }
        
        i=(i+1)%num;

    }
}   
