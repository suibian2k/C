#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(int argc, const char *argv[])
{
    FBDEV fbdev;
    memset(&fbdev,0,sizeof(FBDEV));
    strcpy(fbdev.dev,"/dev/fb0"); 
    if (fb_open(&fbdev) == FALSE)  
    { 
        printf("open frame buffer error\n"); 
        return 0; 
    } 
    fb_memset((void *)fbdev.fb_mem+fbdev.fb_mem_offset,0,fbdev.fb_fix.smem_len);  
    fb_close(&fbdev);
    print_font(&fbdev,500,500,toascii('l'), RED);
    print_string(&fbdev,600,600,"you are a dog", WHITE);
    return 0;
}
