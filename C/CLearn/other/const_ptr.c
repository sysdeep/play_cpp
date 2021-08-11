#include <stdio.h>

int main(){

	int a = 1;
	int b = 2;
	int  const * const p = &a;

	// *p = 3;		// error
	// p = &b;		// error

	// valid
	int  * const p1 = &a;
	*p1 = 3;
	

	// valid
	int  const * p2 = &a;
	p2 = &b;



	printf("a: %d, b: %d, p: %d\n", a, b, *p);

	return 0;
}