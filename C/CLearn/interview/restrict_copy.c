#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
https://ru.wikipedia.org/wiki/Restrict
Ключевое слово restrict позволяет программисту сообщить компилятору, что объявляемый указатель адресует область памяти, на которую не ссылается никакой другой указатель. Гарантию того, что на участок памяти не будут ссылаться более одного указателя, даёт программист.

*/

// вопрос - зачем restrict
int main(){

	int a[3] = {};
	int *b = a;
	int *c = b;
	int result[3] = {};
	
	memcpy(&result, &a, 3);

	for(int i=0; i<3; i++){
		printf("%d", a[i]);
		puts("");
	}

	puts("");

	for(int i=0; i<3; i++){
		printf("%d", result[i]);
		puts("");
	}

	puts("");

	return 0;
}