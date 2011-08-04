#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/user.h>
#include <sys/ioctl.h>
#include <string.h>
#include "main.h"

//open & init a frame buffer
int fb_open(PFBDEV pFbdev)
{
    pFbdev->fb = open(pFbdev->dev,O_RDWR); 
    if (pFbdev->fb<0) 
    {
        printf("Error opening %s: %m. Check kernel kernel config\n", pFbdev->dev);
        return FALSE; 
    }
    if (-1 == ioctl(pFbdev->fb, FBIOGET_VSCREENINFO, &(pFbdev->fb_var))) 
    {
        printf("Ioctl FBIGET_VSCREENIFO");
        return FALSE;
    }
    if (-1 == ioctl(pFbdev->fb, FBIOGET_FSCREENINFO, &(pFbdev->fb_fix))) 
    {
        printf("Ioctl FBIGET_FSCREENIFO");
        return FALSE;
    }

    //map physics address to virtual address
    pFbdev->fb_mem_offset = (unsigned long)(pFbdev->fb_fix.smem_start)&(~PAGE_MASK);
    pFbdev->fb_mem = (unsigned long int )mmap(NULL, pFbdev->fb_fix.smem_len + pFbdev->fb_mem_offset, PROT_READ|PROT_WRITE, MAP_SHARED,pFbdev->fb, 0);

    if (-1 == (long)pFbdev->fb_mem) 
    {
        printf("mmap error! mem:%d offset:%d\n", (unsigned int)pFbdev->fb_mem, (unsigned int)pFbdev->fb_mem_offset);
        return FALSE;
    }

    return TURE;
}

//close frame buffer
int fb_close(PFBDEV pFbdev)
{
    close(pFbdev->fb);
    pFbdev->fb = -1;
    return 0;
}

//get display depth
int  get_display_depth(PFBDEV pFbdev)
{
    if (pFbdev->fb<=0) 
    {
        printf("fb device not open ,open if first\n");
        return FALSE;
    }

    return pFbdev->fb_var.bits_per_pixel;
}

//full screen clear
void fb_memset(void *addr, int c, size_t len)
{
    memset(addr,c,len);
}

//draw a pixel
int fb_one_pixel(PFBDEV pFbdev, int x, int y, u32_t color)
{
    int i;
    u32_t *p = (u32_t *)pFbdev->fb_mem;

    i = x + y*pFbdev->fb_var.xres;

    p[i] = color;

    return 0;

}
