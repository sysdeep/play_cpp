#include <stdio.h>


// допустимо ли такое?
// я ответил - нет...
long chtype(int *x){
	long *y = (long*)x;

	return *y;
}



int main(){

	int a = 5;
	long b;

	b = chtype(&a);


	printf("%d\n", b);
	printf("%d %d\n", sizeof(a), sizeof(b));


	return 0;
}