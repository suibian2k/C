/*********************
*File name: fbtools.h
*/

#ifndef _FBTOOLS_H_
#define _FBTOOLS_H_
#include <linux/fb.h>

#define BLACK   0x00
#define RED     0x00ff0000
#define GREEN   0x0000ff00
#define BLUE    0x000000ff
#define WHITE   0x00ffffff

#define TURE 1
#define FALSE 0
#define FONTDATAMAX 4096

//a framebuffer device structure;
typedef struct fbdev
{
    int fb;
    unsigned long fb_mem_offset;
    unsigned long fb_mem;
    struct fb_fix_screeninfo fb_fix;
    struct fb_var_screeninfo fb_var;
    char dev[20];

}FBDEV, *PFBDEV;

// a mice structure

typedef unsigned int u32_t;
typedef unsigned char u8_t;
typedef char s8_t;


//open & init a frame buffer
//to use this function
//you must set FBDEV.dev = "/dev/fb0"
//or "dev/fbX"
//it's your frame buffer.
int fb_open(PFBDEV pFbdev);

//close frame buffer
int fb_close(PFBDEV  pFbdev);

//get display depth
int  get_display_depth(PFBDEV  pFbdev);

//full screen clear
void fb_memset(void *addr, int c, size_t len);

//draw a pixel
int fb_one_pixel(PFBDEV pFbdev, int x, int y, u32_t color);

int print_font(PFBDEV pFbdev, int x, int y, int asic, unsigned int color);
int  print_string(PFBDEV pFbdev, int x, int y, const char *s, unsigned int color);
#endif
