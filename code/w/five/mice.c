/**********************
 *File name: mouse.c
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "main.h"

static u32_t cursor_pixel[C_WIDTH*C_HEIGHT] = 
{
    BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___, 
    BORD,BORD,T___,T___,T___,T___,T___,T___,T___,T___,
    BORD,X___,BORD,T___,T___,T___,T___,T___,T___,T___,
    BORD,X___,X___,BORD,T___,T___,T___,T___,T___,T___,
    BORD,X___,X___,X___,BORD,T___,T___,T___,T___,T___,
    BORD,X___,X___,X___,X___,BORD,T___,T___,T___,T___,
    BORD,X___,X___,X___,X___,X___,BORD,T___,T___,T___,
    BORD,X___,X___,X___,X___,X___,X___,BORD,T___,T___,
    BORD,X___,X___,X___,X___,X___,X___,X___,BORD,T___,
    BORD,X___,X___,X___,X___,X___,X___,X___,X___,BORD,
    BORD,X___,X___,X___,X___,X___,BORD,BORD,BORD,BORD,
    BORD,X___,X___,BORD,X___,X___,BORD,T___,T___,T___,
    BORD,X___,BORD,X___,BORD,X___,X___,BORD,T___,T___,
    BORD,BORD,T___,T___,BORD,X___,X___,BORD,T___,T___,
    T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___,
    T___,T___,T___,T___,T___,BORD,T___,T___,BORD,T___,
    T___,T___,T___,T___,T___,T___,BORD,BORD,T___,T___

};

static u32_t save_cursor[C_WIDTH*C_HEIGHT];

//  Mouse Test,demo for use mouse operation
int mouse_test(PFBDEV pFbdev)
{
    int fd;
    if ((fd = mouse_open("/dev/input/mice"))<0)
    {
        fprintf(stderr, "Error mouse open:%s\n", strerror(errno));
        exit(1);
    }
    mevent_t mevent;

    /*mouse absolute corrdinate*/
    int m_x = pFbdev->fb_var.xres/2;
    int m_y = pFbdev->fb_var.yres/2;
    mouse_draw(pFbdev, m_x, m_y);

    /*wheel*/
    u8_t buf[] = {0xF3, 0xC8, 0xF3, 0x64, 0xF3, 0x50};
    if(write(fd,buf,sizeof(buf))<sizeof(buf)) 
    {
        fprintf(stderr, "Error write to mice devie:\n");
        fprintf(stderr, "can't use wheel\n");
    }

    while(1) 
    {
        if(mouse_parse(fd, &mevent) == 0) 
        {
            //printf("dx= %d\tdy=%d\t", mevent.dx, mevent.dy, mevent.dz);
            mouse_restore(pFbdev, m_x, m_y); 

            m_x += mevent.dx;
            m_y += mevent.dy;

            if(m_x<0)m_x=0;
            if(m_y<0)m_y=0;
            if(m_x>pFbdev->fb_var.xres-C_WIDTH)m_x=pFbdev->fb_var.xres-C_WIDTH;
            if(m_y>pFbdev->fb_var.yres-C_HEIGHT)m_y=pFbdev->fb_var.yres-C_HEIGHT;
            printf("%d %d\n", m_x, m_y);
            mouse_draw(pFbdev, m_x, m_y);
            //printf("mx=%d\tmy=%d\n", m_x, m_y);
            
            /*switch(mevent.button)
            {
                case 1:
                    printf("left button\n");
                    break;
                case 2:
                    printf("right button\n");
                    break;
                case 4:
                    printf("middle button\n");
                    break;
                case 0:
                    printf("no button\n");
                    break;
                default:
                    break;
            }*/
        }
        else
        {
            //fprintf(stderr, "Error read mouse\n");
            //exit(1);
        }

    }
    close(fd);
    return 0;
}

// return mice device fd
int mouse_open(const char *mdev)
{
    if(NULL == mdev) 
    {
        mdev = "/dev/input/mice";
    }

    return (open(mdev,O_RDWR|O_NONBLOCK));
}

/* 0: read mouse Success
 * -1: error for read mouse
 */
#define READ_MOUSE 8
int mouse_parse(int fd, mevent_t* mevent)
{
    s8_t buf[READ_MOUSE];
    int n;
    if((n = read(fd, buf, READ_MOUSE))>0) 
    {
        /* 1:left key
         * 2:ritht key
         * 4:middle key
         * 0:no button key
         */
        mevent->button = buf[0]&0x07;

        /*incremental for x y*/
        mevent->dx = buf[1];
        mevent->dy = -buf[2];
        mevent->dz = buf[3];
    }
    else
    {
        //sleep(1);
        return -1;
    }
    return 0;
}

static int mouse_save(const PFBDEV pFbdev, int x, int y)
{
    int i,j;

    for (j = 0; j < C_HEIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) 
        {
            if(cursor_pixel[i+j*C_WIDTH]!=T___) 
            {
                save_cursor[i+j*C_WIDTH] = 
                    *(u32_t*)(pFbdev->fb_mem+((x+i)+(y+i)*pFbdev->fb_var.xres)*pFbdev->fb_var.bits_per_pixel/8);
            }
        }
    }
    return 0;
}

int mouse_draw(const PFBDEV pFbdev, int x, int y)
{
    int i,j;

    mouse_save(pFbdev, x, y);

    for (j = 0; j < C_HEIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) 
        {
            if(cursor_pixel[i+j*C_WIDTH]!=T___) 
            {
                fb_one_pixel(pFbdev, x+i, y+j,cursor_pixel[i+j*C_WIDTH]);
            }
        }
    }
    return 0;
}

int mouse_restore(const PFBDEV pFbdev, int x, int y)
{
    int i,j;

    for (j = 0; j < C_HEIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) 
        {
            if(cursor_pixel[i+j*C_WIDTH]!=T___) 
            {
                fb_one_pixel(pFbdev, x+i, y+j,save_cursor[i+j*C_WIDTH]);
            }
        }
    }
    return 0;
}
