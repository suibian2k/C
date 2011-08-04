/*********************
*File name: fbtools.h
*/

#ifndef _FBTOOLS_H_
#define _FBTOOLS_H_
#include <linux/fb.h>

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
typedef struct mevent 
{
    int dx;
    int dy;
    int dz;
    int button;

}mevent_t;

// a information about mice
#define C_WIDTH 10
#define C_HEIGHT 17
#define T___ 0xFFFFFFFF
#define BORD 0x0
#define X___ 0xFFFF


typedef unsigned int u32_t;
typedef unsigned char u8_t;
typedef char s8_t;
    

#define TURE 1
#define FALSE 0

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

//draw a line
int  fb_line(PFBDEV pFbdev, int x1, int y1, int x2, int y2, u32_t color);

/*draw a circle*/
int fb_circle(PFBDEV pFbdev, int x0, int y0, int r, u32_t color);

/*draw a mouse*/
int mouse_draw(const PFBDEV pFbdev, int x, int y);

/*open a  mice equipment*/
int mouse_open(const char *mdev);

int mouse_test(PFBDEV pFbdev);
/**/
int mouse_restore(const PFBDEV pFbdev, int x, int y);

int mouse_parse(int fd, mevent_t* mevent);
#endif
