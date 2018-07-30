#include <stdio.h>
#include <stdlib.h>
int IArray[4] = {1,2,3,4};
int *p;
int address;
void main()
{
    p = IArray;
    printf("%d\r\n",*p);
    p = IArray+1;
    printf("%d\r\n",*p);
    p = IArray++;
    printf("%d\r\n",*p);
}
