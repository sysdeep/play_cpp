#include <stdio.h>
#include "sorting.h"



/*
https://www.geeksforgeeks.org/insertion-sort/
*/
int i1(int *arr, size_t length){
	int i, key, j, count;
	count = 0;
	for(i=1; i < length; i++){
		key = arr[i];
		j = i-1;

		// move elements
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
			count++;
		}
		count++;
		arr[j+1] = key;
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
	printf("Sorting - insertion\n");

	int count;


	print_v(arr1, ARR_SIZE);
	count = i1(arr1, ARR_SIZE);
	print_v(arr1, ARR_SIZE);
	printf("items: %d, count: %d\n", ARR_SIZE, count);


	print_v(arr2, ARR_SIZE);
	count = i1(arr2, ARR_SIZE);
	print_v(arr2, ARR_SIZE);
	printf("items: %d, count: %d\n", ARR_SIZE, count);


	print_v(arr3, ARR_SIZE);
	count = i1(arr3, ARR_SIZE);
	print_v(arr3, ARR_SIZE);
	printf("items: %d, count: %d\n", ARR_SIZE, count);

	return 0;
}