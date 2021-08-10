#include <stdio.h>


/*
найти кол-во 1 в битовом представлении числа

2 -> 1
3 -> 2
4 -> 1
7 -> 3

*/


int find_bits(int number){
	int result = 0;
	while(number){
		
		if(number & 1){
			result++;
		}
		number = number >> 1;
	}
	return result;
}


int main(){

	printf("find bits\n\n");
	int n;
	int r;

	n=1;
	r = find_bits(n);
	printf("number: %d, bits: %d\n", n, r);

	n=2;
	r = find_bits(n);
	printf("number: %d, bits: %d\n", n, r);

	n=3;
	r = find_bits(n);
	printf("number: %d, bits: %d\n", n, r);

	n=4;
	r = find_bits(n);
	printf("number: %d, bits: %d\n", n, r);


	n=7;
	r = find_bits(n);
	printf("number: %d, bits: %d\n", n, r);

	n=34217;
	r = find_bits(n);
	printf("number: %d, bits: %d\n", n, r);

	return 0;
}