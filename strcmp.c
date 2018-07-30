#include<string.h>
void main()
{
char *str1="I am OldWolf";
char *str2="I am Oldwolf";
int cmp;

printf("原字符串分别为：\n%s\n%s\n",str1,str2);
cmp=strcmp(str1,str2);
if (cmp!=0)
   printf("strcmp比较字符串不相同！\n");
else
   printf("strcmp比较字符串相同！\n");
cmp=stricmp(str1,str2);
if (cmp!=0)
   printf("stricmp比较字符串不相同！\n");
else
   printf("stricmp比较字符串相同！\n");
cmp=strcmpi(str1,str2);
if (cmp!=0)
   printf("strcmpi比较字符串不相同！\n");
else
   printf("strcmpi比较字符串相同！\n");
}
