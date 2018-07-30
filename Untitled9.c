#include <stdio.h>
#include <stdlib.h>

#define marco_1  0x20
#define marco_2  0x10
#define marco_3  0x08
#define marco_4  0x04
#define marco_5  0x02
#define marco_6  0x01

typedef enum {
  DG_1         = marco_1 + marco_2,
  DG_2         = marco_3 + marco_4 + marco_6,
  DG_3         = marco_5 + marco_6,
  }testenum;

void main ()
{
int testnum;
testnum = DG_1;
printf("%x\r\n",testnum);
testnum = DG_2;
printf("%x\r\n",testnum);
testnum = DG_3;
printf("%x\r\n",testnum);
}
