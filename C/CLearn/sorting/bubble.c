#include <stdio.h>
#include "sorting.h"



/*
https://www.geeksforgeeks.org/bubble-sort/
*/
int b1(int *arr, size_t length){
	int tmp;
	int count = 0;
	for(int i=0; i < length - 1; i++){
		for(int j = 0; j < length - 1 - i; j++){
			if(arr[j] > arr[j + 1]){
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
			count++;
		}
	}

	return count;
}

void print_v(int *arr, size_t length){
	for(int i=0; i<length; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}


int main(){
	printf("Sorting - bubble\n");

	int count;


	print_v(arr1, ARR_SIZE);
	count = b1(arr1, ARR_SIZE);
	print_v(arr1, ARR_SIZE);
	printf("items: %d, count: %d\n", ARR_SIZE, count);


	print_v(arr2, ARR_SIZE);
	count = b1(arr2, ARR_SIZE);
	print_v(arr2, ARR_SIZE);
	printf("items: %d, count: %d\n", ARR_SIZE, count);


	print_v(arr3, ARR_SIZE);
	count = b1(arr3, ARR_SIZE);
	print_v(arr3, ARR_SIZE);
	printf("items: %d, count: %d\n", ARR_SIZE, count);

	return 0;
}