#include<string.h>
void main()
{
char *str1="I am OldWolf";
char *str2="I am Oldwolf";
int cmp;

printf("ԭ�ַ����ֱ�Ϊ��\n%s\n%s\n",str1,str2);
cmp=strcmp(str1,str2);
if (cmp!=0)
   printf("strcmp�Ƚ��ַ�������ͬ��\n");
else
   printf("strcmp�Ƚ��ַ�����ͬ��\n");
cmp=stricmp(str1,str2);
if (cmp!=0)
   printf("stricmp�Ƚ��ַ�������ͬ��\n");
else
   printf("stricmp�Ƚ��ַ�����ͬ��\n");
cmp=strcmpi(str1,str2);
if (cmp!=0)
   printf("strcmpi�Ƚ��ַ�������ͬ��\n");
else
   printf("strcmpi�Ƚ��ַ�����ͬ��\n");
}
