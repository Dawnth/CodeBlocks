#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------
// Define icon byte definition
//----------------------------------------------
/** PeBus queue structure **/
typedef struct
   {
   int8_t syn;                   // syn
   int8_t idf;                   // idf = identification from
   int8_t idt;                   // idt = identification to
   int8_t no;                    // pn = packet nummber (handled by application)
   int8_t type;                  // pt = ebus control, ebus data
   int8_t len;                   // packet len
   int8_t data[10]; // packet data (the number of data is increase from 24 to 160 for SimBox)
   int8_t dataLen;               // packet data len
   int8_t crc;                   // PeBus crc
   int8_t ttl;                   // time to live in 100ms steps (0.1s - 25.5s)
   int8_t inUse;                 // multiple access sychronization flags
   } PEBUS_QUEUE;

int8_t tempArray[10];
B5_11_0C_StandbyInformation(PEBUS_QUEUE* q)
{
   //Standby is deactivated, send always "normal operation"
   q->data[PEBUS_DB2] = 0;
   memcpy
   return;
}
void main()
{
    int TempData;

    refreshLEDBuffer(Icons);
    // printf("5:   %d\n\r", LED_ICONLIST.GRID_5.GRID_5_Char);
    TempData = testEnable1;
    TempData |= (testEnable2<<1);
    printf("%x\n\r", TempData);
}
