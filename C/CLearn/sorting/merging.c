#include <stdio.h>
#include "sorting.h"

/*
https://www.geeksforgeeks.org/merge-sort/?ref=leftbar-rightbar
*/


void print_v(int *arr, size_t length){
	for(int i=0; i<length; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}



//  2  1
void merge(int *arr, int left_size, int right_size, int start_index){
	int max_size = left_size + right_size;
	int current_index = start_index;
	int left_index = 0;
	int right_index = 0;

	int  L[left_size], R[right_size];
	int i, j ,k;
	
	 /* Copy data to temp arrays L[] and R[] */
	for(i=0; i<left_size;i++)
		L[i] = arr[start_index + i];
	
	for(i=0; i<right_size;i++)
		R[i] = arr[start_index + i + left_size];


	print_v(arr, max_size);
	print_v(L, left_size);
	print_v(R, right_size);


	 /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = start_index; // Initial index of merged subarray
    while (i < left_size && j < right_size) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

	print_v(arr, max_size);

	//  /* Copy the remaining elements of L[], if there
    // are any */
    // while (i < n1) {
    //     arr[k] = L[i];
    //     i++;
    //     k++;
    // }
 
    // /* Copy the remaining elements of R[], if there
    // are any */
    // while (j < n2) {
    //     arr[k] = R[j];
    //     j++;
    //     k++;
    // }

	// while(current_index < max_size + current_index){
		
	// 	// if(left_index >= left_size){

	// 	// }

	// 	if(arr[left_index + start_index] < arr[right_index + start_index]){
	// 		// arr[current_index] = arr[left_index];
	// 		left_index++;
	// 	}
	// 	if(arr[left_index + start_index] > arr[right_index + start_index]){
	// 		// arr[current_index] = arr[right_index];
	// 		right_index++;
	// 	}
	// 	current_index++;
	// }

}


// void merging_sort(int *arr, size_t length, int i){

// 	int left_size = length / 2;
// 	int right_size = length - right_size;

// 	//--- если длина массива == 1 - массив отсортирован
// 	if(length == 1)
// 		return;

// 	merging_sort(arr, left_size, i);
// 	merging_sort(arr, right_size, i + left_size + 1);
// 	merge(arr, left_size, right_size, i);

// }




int main(){

	printf("Sorting - merging\n");

	
	merge(arr1, 5, 5, 0);

	// print_v(arr1, ARR_SIZE);
	// merging_sort(arr1, ARR_SIZE);
	// print_v(arr1, ARR_SIZE);


	// print_v(arr2, ARR_SIZE);
	// merging_sort(arr2, ARR_SIZE);
	// print_v(arr2, ARR_SIZE);


	// print_v(arr3, ARR_SIZE);
	// merging_sort(arr3, ARR_SIZE);
	// print_v(arr3, ARR_SIZE);


	return 0;
}