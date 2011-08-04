#include <stdio.h>
#include "main.h"
#include <string.h>

extern  const unsigned char fontdata_8x16[FONTDATAMAX];

int print_font(PFBDEV pFbdev, int x, int y, int asic, unsigned int color)
{
    int i, j;

    for(j = 0; j < 8; j++) 
    {
        for(i = 0; i < 16; i++) 
        {
            if((fontdata_8x16[asic*16+i]&(0x1<<j)) > 0) 
            {
                fb_one_pixel(pFbdev,x+8-1-j,y+i, color);
            }
        }
        usleep(1000);

    }
}

int  print_string(PFBDEV pFbdev, int x, int y, const char *s, unsigned int color)
{
   int i;
   int len = strlen(s);
   const char *head = s;
   int lx,ly;
   while(1)
   {
       s = head;
        lx = x;
        ly = y;
       for(i = 0; i < len; i++) 
       {
           print_font(pFbdev, lx, ly, toascii(*(s++)), color);
           lx += 8;
       }
        s = head;
        lx = x;
        ly = y;
       for(i = 0; i < len; i++) 
       {
           print_font(pFbdev, lx, ly, toascii(*(s++)), 0x00);
           lx += 8;
       }
   }
}
