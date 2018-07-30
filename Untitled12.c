#include <stdio.h>
#include <stdlib.h>

int RF_address;
int RF_correct[] = {0x11,0x22,0x33};
int RF_correct2[] = {0x66,0x55,0xdd};

void main()
{
    printf("%d\n\r", sizeof(int));
    RF_address = RF_correct[0]<<16 | RF_correct[1]<<8 | RF_correct[2]&0x0F;
    printf("%x\n\r", RF_address);
    RF_address = RF_correct2[0]<<16 | RF_correct2[1]<<8 | RF_correct2[2]&0x0F;
    printf("%x\n\r", RF_address);
}
