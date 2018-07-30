#include <stdio.h>
char i = -113;
unsigned char j = 241;
void main (void)
{
    char temp1 = i + j;
    unsigned char temp2 = i + j;
    printf("%d  %d",temp1,temp2);
    return 0;
}
