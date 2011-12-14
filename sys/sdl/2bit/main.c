/*
  check for font rotation
*/

#include "u8g.h"
#include <stdlib.h>
#include <stdio.h>


int u8g_sdl_get_key(void);


int main(void)
{
  u8g_uint_t w,h;
  u8g_t u8g;
  
  u8g_Init(&u8g, &u8g_dev_sdl_2bit);
  u8g_FirstPage(&u8g);
  do
  {
    u8g_SetFont(&u8g, u8g_font_10x20);
    u8g_SetFont(&u8g, u8g_font_fur25);
    w = u8g_GetFontBBXWidth(&u8g);
    h = u8g_GetFontBBXHeight(&u8g);
    
    u8g_SetColorIndex(&u8g, 1);
    u8g_DrawStr(&u8g, 30, 35, 0, "gabc");
    u8g_SetColorIndex(&u8g, 2);
    u8g_DrawStr(&u8g, 30+1, 35+1, 0, "gabc");
    u8g_SetColorIndex(&u8g, 3);
    u8g_DrawStr(&u8g, 30+2, 35+2, 0, "gabc");
  }while( u8g_NextPage(&u8g) );
  
  while( u8g_sdl_get_key() < 0 )
    ;
  
  return 0;
}



