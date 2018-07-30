#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------
// Define icon byte definition
//----------------------------------------------
#define ICON_DOT        0x0001
#define ICON_FLAME      0x0002
#define ICON_TAP        0x0004
#define ICON_FAN        0x0008
#define ICON_REMOTE     0x0010
#define ICON_DEGREE     0x0020
#define ICON_LITER      0x0040
#define ICON_PERMINUTE  0x0080
#define ICON_NORMAL     0x0100
#define ICON_ECO        0x0200
#define ICON_BATHTUB    0x0400

int Icons = 32;
typedef struct
{
    union
    {
       int GRID_5_Char;
       struct
       {
           int GRID_5_Bit0           :1;  // not use
           int IconFanStatus         :2;  // Fan status icon
           int IconTapStatus         :2;  // Tap status icon
           int IconFlameStatus       :2;  // Flame status icon
           int GRID_5_Bit7           :1;  // not use
       } GRID_5_bits;
    } GRID_5;

    union
    {
       int GRID_6_Char;
       struct
       {
           int IconBathtubMode       :2;  // Bathtub mode icon
           int IconPerMinute         :1;  // Per minute icon
           int IconLitre             :1;  // Litre icon
           int IconCentigradeDegree  :1;  // Centigrade degree icon
           int IconRemoteStatus      :2;  // Remote control icon
           int GRID_6_Bit7           :1;  // not use
       } GRID_6_bits;
    } GRID_6;

    union
    {
       int GRID_7_Char;
       struct
       {
           int GRID_7_Bit0           :1;  // not use
           int GRID_7_Bit1           :1;  // not use
           int IconDot               :1;  // Dot icon
           int IconNormalMode        :2;  // Normal mode icon
           int IconECOMode           :2;  // ECO mode icon
           int GRID_7_Bit7           :1;  // not use
       } GRID_7_bits;
    } GRID_7;
} LED_ICONLISTStruct;

LED_ICONLISTStruct          LED_ICONLIST;
int CurrentDiagPointIndex;

void refreshLEDBuffer(int icons)
{
    LED_ICONLIST.GRID_5.GRID_5_bits.IconFanStatus        = (Icons&ICON_FAN       != 0)?0x03:0x00;
    LED_ICONLIST.GRID_5.GRID_5_bits.IconTapStatus        = (Icons&ICON_TAP       != 0)?0x03:0x00;
    LED_ICONLIST.GRID_5.GRID_5_bits.IconFlameStatus      = (Icons&ICON_FLAME     != 0)?0x03:0x00;

    LED_ICONLIST.GRID_6.GRID_6_bits.IconBathtubMode      = (Icons&ICON_BATHTUB   != 0)?0x03:0x00;
    LED_ICONLIST.GRID_6.GRID_6_bits.IconPerMinute        = (Icons&ICON_PERMINUTE != 0)?0x01:0x00;
    LED_ICONLIST.GRID_6.GRID_6_bits.IconLitre            = (Icons&ICON_LITER     != 0)?0x01:0x00;
    LED_ICONLIST.GRID_6.GRID_6_bits.IconCentigradeDegree = (Icons&ICON_DEGREE    != 0)?0x01:0x00;
    LED_ICONLIST.GRID_6.GRID_6_bits.IconRemoteStatus     = (Icons&ICON_REMOTE    != 0)?0x03:0x00;

    LED_ICONLIST.GRID_7.GRID_7_bits.IconDot              = (Icons&ICON_DOT       != 0)?0x01:0x00;
    LED_ICONLIST.GRID_7.GRID_7_bits.IconNormalMode       = (Icons&ICON_NORMAL    != 0)?0x03:0x00;
    LED_ICONLIST.GRID_7.GRID_7_bits.IconECOMode          = (Icons&ICON_ECO       != 0)?0x03:0x00;

}
int RF_Buffer[5] = {8, 0, 5, 93, 106};
int testEnable1 = 1;
int testEnable2 = 0;
void main()
{
    int TempData;

    refreshLEDBuffer(Icons);
    //printf("5:   %d\n\r", LED_ICONLIST.GRID_5.GRID_5_Char);
    //printf("6:   %d\n\r", LED_ICONLIST.GRID_6.GRID_6_Char);
    //printf("7:   %d\n\r", LED_ICONLIST.GRID_7.GRID_7_Char);
    //printf("%d\n\r", Icons&ICON_DEGREE);
    //printf("%d\n\r", ((Icons&ICON_DEGREE)    != 0));
    //printf("%d\n\r", LED_ICONLIST.GRID_6.GRID_6_bits.IconCentigradeDegree);
    //printf("%d\n\r", (LocalDiagPointIndex %% 100));
    //printf("%d\n\r", RF_Buffer[3]&0x01);
    TempData = testEnable1;
    TempData |= (testEnable2<<1);
    printf("%x\n\r", TempData);
}
