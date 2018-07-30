#include <stdio.h>
int * iPoint;
int addr;
int test;
int temp;
// address test of pointer
void main ()
{
    addr = 100;
    iPoint = &test;
printf("iPoint end address: %d\r\n", iPoint);

    temp = (int)&iPoint;
printf("temp(iPoint start address): %d\r\n", temp);

    temp = (int)((addr * 2) / 3);
printf("temp(calculation value): %d\r\n", temp);

    // If iPoint is int, the calculation iPoint + temp * 4
    // If iPoint is char, the calculation iPoint + temp * 1
    iPoint += ((addr * 2) / 3);
printf("iPoint address after calculation: %d\r\n", iPoint);
}
