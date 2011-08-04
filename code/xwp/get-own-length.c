#include <stdio.h>
#include <string.h>
int get_length(char *str1, char *str2);
int main(int argc, const char *argv[])
{
    //char s1[4096] = "sdfg";
    //char s2[4096] = "cdfb";

    char s1[4096];
    char s2[4096];
    printf("string1\n");
    fgets(s1,4096,stdin);
    printf("string2\n");
    fgets(s2,4096,stdin);

    printf("%s\n",s1);
    printf("%s\n",s2);

    printf("%d\n",get_length(s1, s2));

    return 0;
}

int get_length(char *str1, char *str2)
{
    char *p = str1;
    char *p2 = str2;

    int i = 0;
    int count = 0;

    while ('\0' != *p)
    {
        while ('\0' != *p2) 
        {
            for (i = 1; (i < strlen(p))&&('\0'!= *p2); i++) 
            {
                printf("%d\n",i);
                if(0 != strncmp(p,p2,i))
                {
                    break;
                }
            }
            count = (count>(i-1)?count:(i-1));
            p2++; 
        }
        p2 = str2;
        p++;
    }
    return count;

}
