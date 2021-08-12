/*
	пример исаользования стандартной сортировки qsort
*/
#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

int comp(const int *a, const int *b);

void print_v(int *arr, size_t length){
	for(int i=0; i<length; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}


void QSort(int *arr, ssize_t len){
	qsort(arr, ARR_SIZE, sizeof(int), (int(*)(const void *, const void *))comp);
}

int main(){



	print_v(arr1, ARR_SIZE);
	QSort(arr1, ARR_SIZE);
	print_v(arr1, ARR_SIZE);

	print_v(arr2, ARR_SIZE);
	QSort(arr2, ARR_SIZE);
	print_v(arr2, ARR_SIZE);

	print_v(arr3, ARR_SIZE);
	QSort(arr3, ARR_SIZE);
	print_v(arr3, ARR_SIZE);

	

	return 0;
}


int comp(const int *a, const int *b){
	return *a - *b;
}