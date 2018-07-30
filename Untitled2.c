#include <stdio.h>

struct A{

        char a;

        char b;

};



struct B{

        char a;

         char b;

         double c;

 };



 struct C{

         char a;

 };



 struct D{

         char a;

         short c[0];

 };



 struct E{

         char a;

         int c[0];

 };



 int main()
 {

         printf("sizeof(struct A): %d\n", sizeof(struct A));

         printf("sizeof(struct B): %d\n", sizeof(struct B));

         printf("alignof(struct B): %d\n", __alignof__(struct B));

         printf("sizeof(struct C): %d\n", sizeof(struct C));

         printf("sizeof(struct D): %d\n", sizeof(struct D));

         printf("sizeof(struct E): %d\n", sizeof(struct E));



         return 0;

 }
