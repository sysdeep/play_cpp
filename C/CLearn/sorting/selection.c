#include <stdio.h>
#include "sorting.h"


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/*
https://www.geeksforgeeks.org/selection-sort/
*/
int s1(int *arr, size_t length){
	int i, min_idx, j, count;
	count = 0;

	for(i=0; i < length-1; i++){
		// find min index
		min_idx = i;

		for(j = i+1; j<length; j++){
			if(arr[j] < arr[min_idx]){
				min_idx = j;
				count++;
			}

			swap(&arr[min_idx], &arr[i]);
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

	printf("Sorting - selection\n");

	int count;
	

	print_v(arr1, ARR_SIZE);
	count = s1(arr1, ARR_SIZE);
	print_v(arr1, ARR_SIZE);
	printf("items: %d, count: %d\n", ARR_SIZE, count);


	print_v(arr2, ARR_SIZE);
	count = s1(arr2, ARR_SIZE);
	print_v(arr2, ARR_SIZE);
	printf("items: %d, count: %d\n", ARR_SIZE, count);


	print_v(arr3, ARR_SIZE);
	count = s1(arr3, ARR_SIZE);
	print_v(arr3, ARR_SIZE);
	printf("items: %d, count: %d\n", ARR_SIZE, count);


	return 0;
}