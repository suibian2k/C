    #include <stdio.h>
    
    int main(int argc, const char *argv[])
    {
        char a[5] = {0,1,2,3,4};
        short *p = (short *)(a+2);
        short i = *p;
        printf("%x\n",i);
        int d = 0x1234;
        
        return 0;
    }
