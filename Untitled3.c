#include <stdio.h>

int a = 4;
int b = 4;
int c = 0;
char str[] = "http://www.ibegroup.com/";
char *p = str;
int n = 10;

void Foo ( char Foostr[100]);
int main()
{
    a = 4;
    printf("a1 = %d\n", a += (a++));
    a = 4;
    printf("a11 = %d\n", a = a + (a++));
    a = 4;
    printf("a12 = %d\n", a = (a++) + a);
    a = 4;
    printf("a2 = %d\n", a += (++a));
    a = 4;b = 4;c =0;
    printf("a21 = %d\n", c = b + (++a));
    a = 4;
    printf("a22 = %d\n", a = (++a) + a);
    a = 1;
    printf("\n\naX1 = %d\n", a = (++a));
    a = 1;
    printf("aX2 = %d\n", a = (++a) + (++a));
    a = 1;
    printf("aX3 = %d\n", a = (++a) + (++a) + (++a));
    a = 1;
    printf("aX4 = %d\n", a = (++a) + (++a) + (++a) + (++a));
    a = 1;
    printf("aX5 = %d\n\n", a = (++a) + (++a) + (++a) + (++a) + (++a));
    //a = 4;
    //printf("a3 = %d", (++a) += a);
    //a = 4;
    //printf("a4 = %d\n", (++a) += (a++));

    printf("\nstr = %d\n",sizeof (str ));
    printf("p = %d\n",sizeof ( p ));
    printf("p = %d\n",p);
    printf("p = %c\n",*p);
    printf("n = %d\n",sizeof ( n ));

    void *q = malloc( 100 );
    printf("\nq = %d\n",sizeof ( q ));
    Foo(str[100]);
}
void Foo ( char Foostr[100])
{
    printf("\nFoostr = %d\n",sizeof( Foostr ));
    printf("char = %d\n",sizeof( char ));
    printf("short = %d\n",sizeof( short ));
    printf("int = %d\n",sizeof( int ));
    printf("double = %d\n",sizeof( double ));
    printf("float = %d\n",sizeof( float ));
}
