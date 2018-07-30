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

int DG_Array[] =
{
LED_NONE,
LED_A + LED_B + LED_C + LED_D + LED_E + LED_F,
LED_B + LED_C,
LED_A + LED_B + LED_D + LED_E + LED_G,
LED_A + LED_B + LED_C + LED_D + LED_G,
LED_B + LED_C + LED_F + LED_G,
LED_A + LED_C + LED_D + LED_F + LED_G,
LED_A + LED_C + LED_D + LED_E + LED_F + LED_G,
LED_A + LED_B + LED_C,
LED_A + LED_B + LED_C + LED_D + LED_E + LED_F + LED_G,
LED_A + LED_B + LED_C + LED_D + LED_F + LED_G,
LED_A + LED_B + LED_C + LED_E + LED_F + LED_G,
LED_C + LED_D + LED_E + LED_F + LED_G,
LED_A + LED_D + LED_E + LED_F,
LED_B + LED_C + LED_D + LED_E + LED_G,
LED_A + LED_D + LED_E + LED_F + LED_G,
LED_A + LED_E + LED_F + LED_G,
LED_A + LED_C + LED_D + LED_F + LED_G,
LED_A + LED_B + LED_C + LED_D + LED_E + LED_F,
LED_A + LED_B + LED_E + LED_F + LED_G,
LED_D,
LED_B + LED_C + LED_G,
LED_E + LED_F + LED_G,
LED_G,
LED_C + LED_D + LED_E + LED_F + LED_G,
LED_D + LED_E + LED_G,
LED_B + LED_C + LED_D + LED_E + LED_G,
LED_C + LED_E + LED_F + LED_G,
LED_C + LED_E + LED_G,
LED_C + LED_D + LED_E + LED_G,
LED_E + LED_G,
LED_D + LED_E + LED_F + LED_G,
LED_C + LED_D + LED_E,
LED_C + LED_G,
LED_A + LED_B,
LED_D + LED_E,
LED_F + LED_G,
};
typedef struct
{
   DG    GRID_1;                          // Digit number 1
   DG    GRID_2;                          // Digit number 2
   DG    GRID_3;                          // Digit number 3
   DG    GRID_4;                          // Digit number 4


   union
   {
      int GRID_5_Char;
      struct
      {
         unsigned char GRID_5_Bit0           :1;  // not use
         unsigned char IconFanStatus         :2;  // Fan status icon
         unsigned char IconTapStatus         :2;  // Tap status icon
         unsigned char IconFlameStatus       :2;  // Flame status icon
         unsigned char GRID_5_Bit7           :1;  // not use
      } GRID_5_bits;
   } GRID_5;

   union
   {
      int GRID_6_Char;
      struct
      {
         unsigned char IconBathtubMode       :2;  // Bathtub mode icon
         unsigned char IconPerMinute         :1;  // Per minute icon
         unsigned char IconLitre             :1;  // Litre icon
         unsigned char IconCentigradeDegree  :1;  // Centigrade degree icon
         unsigned char IconRemoteStatus      :2;  // Remote control icon
         unsigned char GRID_6_Bit7           :1;  // not use
      } GRID_6_bits;
   } GRID_6;

   union
   {
      int GRID_7_Char;
      struct
      {
         unsigned char GRID_7_Bit0           :1;  // not use
         unsigned char GRID_7_Bit1           :1;  // not use
         unsigned char IconDot               :1;  // Dot icon
         unsigned char IconNormalMode        :2;  // Normal mode icon
         unsigned char IconECOMode           :2;  // ECO mode icon
         unsigned char GRID_7_Bit7           :1;  // not use
      } GRID_7_bits;
   } GRID_7;

} LED_ICONLISTStruct;

LED_ICONLISTStruct LED_ICONLIST;

void init()
{
   int i;
   for(i = 0; i < LED_GRIDBUFFNUM; i++)
   {
      LED_GRIDBuffer[i] = 0;
   }

   LED_SetAllGridData(LED_ALL);
   LED_SetAllGridData(LED_NONE);
}

// set all LED module display data
void LED_SetAllGridData(int iReserve)
{
   int i;

   for(i = 0; i < LED_GRIDBUFFNUM; i++)
   {
      LED_GRIDBuffer[i] = iReserve;
   }
}
void refillData()
{
   // Set Digit data
   LED_GRIDBuffer[0] = LED_ICONLIST.GRID_1;
   LED_GRIDBuffer[2] = LED_ICONLIST.GRID_2;
   LED_GRIDBuffer[4] = LED_ICONLIST.GRID_3;
   LED_GRIDBuffer[6] = LED_ICONLIST.GRID_4;
   LED_GRIDBuffer[8] = LED_ICONLIST.GRID_5.GRID_5_Char;
   LED_GRIDBuffer[10] = LED_ICONLIST.GRID_6.GRID_6_Char;
   LED_GRIDBuffer[12] = LED_ICONLIST.GRID_7.GRID_7_Char;

   // DRID_5
   // IconFanStatus is 2 bits, so need to fill 11B(0x03) with 1 bit to the left
   if (LED_ICONLIST.GRID_5.GRID_5_bits.IconFanStatus == TRUE)
   {
      LED_GRIDBuffer[8] |= 0x06;
   }
   else
   {
      LED_GRIDBuffer[8] &= ~0x06;
   }
   // IconTapStatus is 2 bits, so need to fill 11B(0x03) with 3 bits to the left
   if (LED_ICONLIST.GRID_5.GRID_5_bits.IconTapStatus == TRUE)
   {
      LED_GRIDBuffer[8] |= 0x18;
   }
   else
   {
      LED_GRIDBuffer[8] &= ~0x18;
   }
   // IconFlameStatus is 2 bits, so need to fill 11B(0x03) with 5 bits to the left
   if (LED_ICONLIST.GRID_5.GRID_5_bits.IconFlameStatus == TRUE)
   {
      LED_GRIDBuffer[8] |= 0x60;
   }
   else
   {
      LED_GRIDBuffer[8] &= ~0x60;
   }

   // DRID_6
   // IconBathtubMode is 2 bits, so need to fill 11B(0x03) with 0 bits to the left
   if (LED_ICONLIST.GRID_6.GRID_6_bits.IconBathtubMode == TRUE)
   {
      LED_GRIDBuffer[10] |= 0x03;
   }
   else
   {
      LED_GRIDBuffer[10] &= ~0x03;
   }
   // IconRemoteStatus is 2 bits, so need to fill 11B(0x03) with 5 bits to the left
   if (LED_ICONLIST.GRID_6.GRID_6_bits.IconRemoteStatus == TRUE)
   {
      LED_GRIDBuffer[10] |= 0x60;
   }
   else
   {
      LED_GRIDBuffer[10] &= ~0x60;
   }

   // DRID_7
   // IconNormalMode is 2 bits, so need to fill 11B(0x03) with 3 bits to the left
   if (LED_ICONLIST.GRID_7.GRID_7_bits.IconNormalMode == TRUE)
   {
      LED_GRIDBuffer[12] |= 0x18;
   }
   else
   {
      LED_GRIDBuffer[12] &= ~0x18;
   }
   // IconECOMode is 2 bits, so need to fill 11B(0x03) with 5 bits to the left
   if (LED_ICONLIST.GRID_7.GRID_7_bits.IconECOMode == TRUE)
   {
      LED_GRIDBuffer[12] |= 0x60;
   }
   else
   {
      LED_GRIDBuffer[12] &= ~0x60;
   }
}
void main()
{
   int i;
   init();

   LED_ICONLIST.GRID_1 = DG_LETTER_F;
   LED_ICONLIST.GRID_2 = DG_VALUE_1;
   LED_ICONLIST.GRID_3 = DG_VALUE_6;
   LED_ICONLIST.GRID_4 = DG_VALUE_8;

   LED_ICONLIST.GRID_5.GRID_5_bits.GRID_5_Bit0 = TRUE;
   LED_ICONLIST.GRID_5.GRID_5_bits.IconFanStatus = TRUE;
   LED_ICONLIST.GRID_5.GRID_5_bits.IconTapStatus = FALSE;
   LED_ICONLIST.GRID_5.GRID_5_bits.IconFlameStatus = TRUE;
   LED_ICONLIST.GRID_5.GRID_5_bits.GRID_5_Bit7 = FALSE;



   LED_ICONLIST.GRID_6.GRID_6_bits.IconBathtubMode = TRUE;
   LED_ICONLIST.GRID_6.GRID_6_bits.IconPerMinute = TRUE;
   LED_ICONLIST.GRID_6.GRID_6_bits.IconLitre = FALSE;
   LED_ICONLIST.GRID_6.GRID_6_bits.IconCentigradeDegree = TRUE;
   LED_ICONLIST.GRID_6.GRID_6_bits.IconRemoteStatus = FALSE;
   LED_ICONLIST.GRID_6.GRID_6_bits.GRID_6_Bit7 = FALSE;



   LED_ICONLIST.GRID_7.GRID_7_bits.GRID_7_Bit0 = TRUE;
   LED_ICONLIST.GRID_7.GRID_7_bits.GRID_7_Bit1 = TRUE;
   LED_ICONLIST.GRID_7.GRID_7_bits.IconDot = FALSE;
   LED_ICONLIST.GRID_7.GRID_7_bits.IconNormalMode = TRUE;
   LED_ICONLIST.GRID_7.GRID_7_bits.IconECOMode = FALSE;
   LED_ICONLIST.GRID_7.GRID_7_bits.GRID_7_Bit7 = FALSE;


   refillData();

// ************************************************************//
   for(i = 0; i < LED_GRIDBUFFNUM; i++)
   {
      if (i%2 == 0)
      {
         //printf("GRID%d: %x\r\n",i / 2 + 1,LED_GRIDBuffer[i]);
      }
   }
   //printf("\r\n\r\n\r\n\r\n");



   LED_ICONLIST.GRID_1 = DG_LETTER_d;
   LED_ICONLIST.GRID_2 = DG_LETTER_u;
   LED_ICONLIST.GRID_3 = DG_LETTER_u;
   LED_ICONLIST.GRID_4 = DG_LETTER_u;

   LED_ICONLIST.GRID_5.GRID_5_bits.GRID_5_Bit0 = FALSE;
   LED_ICONLIST.GRID_5.GRID_5_bits.IconFanStatus = FALSE;
   LED_ICONLIST.GRID_5.GRID_5_bits.IconTapStatus = FALSE;
   LED_ICONLIST.GRID_5.GRID_5_bits.IconFlameStatus = TRUE;
   LED_ICONLIST.GRID_5.GRID_5_bits.GRID_5_Bit7 = FALSE;



   LED_ICONLIST.GRID_6.GRID_6_bits.IconBathtubMode = FALSE;
   LED_ICONLIST.GRID_6.GRID_6_bits.IconPerMinute = TRUE;
   LED_ICONLIST.GRID_6.GRID_6_bits.IconLitre = TRUE;
   LED_ICONLIST.GRID_6.GRID_6_bits.IconCentigradeDegree = TRUE;
   LED_ICONLIST.GRID_6.GRID_6_bits.IconRemoteStatus = TRUE;
   LED_ICONLIST.GRID_6.GRID_6_bits.GRID_6_Bit7 = FALSE;



   LED_ICONLIST.GRID_7.GRID_7_bits.GRID_7_Bit0 = FALSE;
   LED_ICONLIST.GRID_7.GRID_7_bits.GRID_7_Bit1 = FALSE;
   LED_ICONLIST.GRID_7.GRID_7_bits.IconDot = TRUE;
   LED_ICONLIST.GRID_7.GRID_7_bits.IconNormalMode = TRUE;
   LED_ICONLIST.GRID_7.GRID_7_bits.IconECOMode = FALSE;
   LED_ICONLIST.GRID_7.GRID_7_bits.GRID_7_Bit7 = FALSE;


   refillData();

   for(i = 0; i < LED_GRIDBUFFNUM; i++)
   {
      if (i%2 == 0)
      {
         //printf("GRID%d: %x\r\n",i / 2 + 1,LED_GRIDBuffer[i]);
      }
   }

   //printf("\r\n");
   for(i = 0; i < sizeof(DG_Array)/sizeof(int); i++)
   {
       printf("%d/%d: %x\r\n", i+1, sizeof(DG_Array)/sizeof(int), DG_Array[i]);
   }

}
