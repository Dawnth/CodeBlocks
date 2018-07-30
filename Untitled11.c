#include <stdio.h>
#include <stdlib.h>

#define LED_GRIDBUFFNUM   14
int LED_GRIDBuffer[LED_GRIDBUFFNUM];

#define TRUE   1
#define FALSE  0

// LED seg value
#define LED_A      0x40
#define LED_B      0x20
#define LED_C      0x10
#define LED_D      0x08
#define LED_E      0X04
#define LED_F      0x02
#define LED_G      0x01
#define LED_NONE   0x00
#define LED_ALL    0x7F
// DIG value
typedef enum
{
   DG_OFF         =  LED_NONE,
   DG_VALUE_0     =  LED_A + LED_B + LED_C + LED_D + LED_E + LED_F,
   DG_VALUE_1     =  LED_B + LED_C,
   DG_VALUE_2     =  LED_A + LED_B + LED_D + LED_E + LED_G,
   DG_VALUE_3     =  LED_A + LED_B + LED_C + LED_D + LED_G,
   DG_VALUE_4     =  LED_B + LED_C + LED_F + LED_G,
   DG_VALUE_5     =  LED_A + LED_C + LED_D + LED_F + LED_G,
   DG_VALUE_6     =  LED_A + LED_C + LED_D + LED_E + LED_F + LED_G,
   DG_VALUE_7     =  LED_A + LED_B + LED_C,
   DG_VALUE_8     =  LED_A + LED_B + LED_C + LED_D + LED_E + LED_F + LED_G,
   DG_VALUE_9     =  LED_A + LED_B + LED_C + LED_D + LED_F + LED_G,
   DG_LETTER_A    =  LED_A + LED_B + LED_C + LED_E + LED_F + LED_G,
   DG_LETTER_B    =  LED_C + LED_D + LED_E + LED_F + LED_G,
   DG_LETTER_C    =  LED_A + LED_D + LED_E + LED_F,
   DG_LETTER_D    =  LED_B + LED_C + LED_D + LED_E + LED_G,
   DG_LETTER_E    =  LED_A + LED_D + LED_E + LED_F + LED_G,
   DG_LETTER_F    =  LED_A + LED_E + LED_F + LED_G,
   DG_LETTER_S    =  LED_A + LED_C + LED_D + LED_F + LED_G,
   DG_LETTER_O    =  LED_A + LED_B + LED_C + LED_D + LED_E + LED_F,
   DG_LETTER_P    =  LED_A + LED_B + LED_E + LED_F + LED_G,
   DG_UNDERSCORE  =  LED_D,
   DG_RESET_LEFT  =  LED_B + LED_C + LED_G,
   DG_RESET_RIGHT =  LED_E + LED_F + LED_G,
   DG_MINUS       =  LED_G,
   DG_LETTER_b    =  LED_C + LED_D + LED_E + LED_F + LED_G,
   DG_LETTER_c    =  LED_D + LED_E + LED_G,
   DG_LETTER_d    =  LED_B + LED_C + LED_D + LED_E + LED_G,
   DG_LETTER_h    =  LED_C + LED_E + LED_F + LED_G,
   DG_LETTER_n    =  LED_C + LED_E + LED_G,
   DG_LETTER_o    =  LED_C + LED_D + LED_E + LED_G,
   DG_LETTER_r    =  LED_E + LED_G,
   DG_LETTER_t    =  LED_D + LED_E + LED_F + LED_G,
   DG_LETTER_u    =  LED_C + LED_D + LED_E,
   DG_LOW_ARROW1  =  LED_C + LED_G,
   DG_LOW_ARROW2  =  LED_A + LED_B,
   DG_HIGH_ARROW1 =  LED_D + LED_E,
   DG_HIGH_ARROW2 =  LED_F + LED_G,
} DG;

int DigitTestTable[]={
DG_VALUE_0,
DG_VALUE_1,
DG_VALUE_2,
DG_VALUE_3,
DG_VALUE_4,
DG_VALUE_5,
DG_VALUE_6,
DG_VALUE_7,
DG_VALUE_8,
DG_VALUE_9,
DG_OFF,
};
int testShowValue;
void main()
{
   int testRFIndex;
   int i;

   for (i = 0; i < 10; i++)
   {
       printf("%d    ",DigitTestTable[i]);
   }

   printf("\r\n***********************\r\n");

   testShowValue = 157;

   testRFIndex = testShowValue / 1000;
   //LED_ICONLIST.GRID_2 = DigitTestTable[testRFIndex];
   printf("1:  %d  %d\r\n",testRFIndex,DigitTestTable[testRFIndex]);

   testRFIndex = (testShowValue / 100) % 10;
   //LED_ICONLIST.GRID_2 = DigitTestTable[testRFIndex];
   printf("2:  %d  %d\r\n",testRFIndex,DigitTestTable[testRFIndex]);

   testRFIndex = (testShowValue / 10) % 10;
   //LED_ICONLIST.GRID_3 = DigitTestTable[testRFIndex];
   printf("3:  %d  %d\r\n",testRFIndex,DigitTestTable[testRFIndex]);

   testRFIndex = testShowValue % 10;
   //LED_ICONLIST.GRID_4 = DigitTestTable[testRFIndex];
   printf("4:  %d  %d\r\n",testRFIndex,DigitTestTable[testRFIndex]);


}
