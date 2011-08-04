#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    char s[100]; 
    int i = 0;
    FILE *fp = NULL;

    if(!(fp =  fopen("text1", "r+")))
    {
        perror("open");
        exit(0);
    }

    //for (i = 0; i < 20; i++) 
    //{
        //putc('a'+i, fp);
    //}

    fflush(fp);

    for (i = 0; i < 99; i++) 
    {
        if (EOF == (s[i] = getc(fp))) 
        {
            s[i] = '\0';
            break;
        }
    }
    
    
    
    
    printf("%s\n", s);



    return 0;
}
