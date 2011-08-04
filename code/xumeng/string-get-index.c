#include <stdio.h>
#include <string.h>

//the point is the import
int main(int argc, const char *argv[])
{
    char s[] = "adc df dfds ssd dfd df";
    char word[] = "fd";
    printf("%d\n", getIndex(s,word));
    
    return 0;
}

int getIndex(char *s, char *word)
{
        char * st = s;
        
        while (strncmp(st,word,strlen(word)) != 0) 
        {
            if ((st-s+1) > strlen(st) - strlen(word)) 
            {
                return -1;
            }
            printf("%s\n", st);
           st++;
        }

        return st-s;
}
