#include <stdio.h>
#include <stdlib.h>


#define LED_A        0x40
#define LED_B        0x20
#define LED_C        0x10
#define LED_D        0x08
#define LED_E        0x04
#define LED_F        0x02
#define LED_G        0x01
const unsigned char TBL_LCD_DSP[] =
{
   LED_A + LED_B + LED_C + LED_D + LED_E + LED_F,          // 0
   LED_B + LED_C,                                          // 1
   LED_A + LED_B + LED_D + LED_E + LED_G,                  // 2
   LED_A + LED_B + LED_C + LED_D + LED_G,                  // 3
   LED_B + LED_C + LED_F + LED_G,                          // 4
   LED_A + LED_C + LED_D + LED_F + LED_G,                  // 5
   LED_A + LED_G + LED_C + LED_D + LED_E + LED_F,          // 6
   LED_A + LED_B + LED_C,                                  // 7
   LED_A + LED_B + LED_C + LED_D + LED_E + LED_F + LED_G,  // 8
   LED_A + LED_B + LED_C + LED_D + LED_F + LED_G,          // 9
   LED_G,                                                  // -
   LED_A + LED_D + LED_E + LED_F,                          // C
   LED_B + LED_C + LED_D + LED_E + LED_G,                  // d
   LED_A + LED_D + LED_E + LED_F + LED_G,                  // E
   LED_A + LED_E + LED_F + LED_G,                          // F
   LED_D + LED_E + LED_F,                                  // L
   LED_A + LED_B + LED_C + LED_E + LED_F,                  // N
   LED_B + LED_C + LED_D + LED_E + LED_F,                  // U
   0x00, 0x00, 0x00,
};

void main()
{
   int i = 0;
   for (i; i < 19; i++ )
   {
      printf("%d   0x%x\r\n",i,TBL_LCD_DSP[i]);
   }
}
