#include <stdio.h>
#include <string.h>
//delete ' ' need't other array
int main(int argc, const char *argv[])
{

    char str[20] = "this is a C world!";
    char * p = str;
    char * tp = p;
    //while(*p != '\0')
    //{
        //if (*p == ' ') 
        //{
            //tp = p;
            //while(*p != '\0')
            //{
            //  *p = *(p+1);
            //  p++;
            // }
            //p = tp;
        //}
        //p++;
    //}
    //more fast 
    
    while( *tp != '\0')
    {
        while(*tp == ' ') tp++; 
        if (p != tp) 
        {
            *p = *tp;
        }
        p++;
        tp++;
    }
    

    *p = '\0';
    printf("len = %d\t%s\n", strlen(str),str);
    putchar('\n');
    return 0;


}
