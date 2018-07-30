#include <stdio.h>
#include <stdlib.h>
char CArray[] = "abcdefg";
char *p;
int address;
void main()
{
    p = CArray;
    address = (int)&p;
    printf("%d\r\n",sizeof(p));
    printf("%d\r\n",&p);
    printf("%d\r\n",address);
}
