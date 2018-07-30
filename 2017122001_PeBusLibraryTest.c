#include <stdio.h>
#pragma comment (lib,"libPeBusLibrary")
//#pragma comment (lib,"ws2_32")
extern int myMultiple(int a, int b);
int main() {
	printf("lib multiple value is %d", myMultiple(2, 3));
	getchar();
	return 0;
}
