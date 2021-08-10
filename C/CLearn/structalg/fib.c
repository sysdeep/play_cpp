#include <stdio.h>

/*
0, 1, 1, 2, 3, 5, 8, 13, 21....
*/

int fib_rec(int n){
    if(n == 0 || n == 1)
        return 1;

    return fib_rec(n-1) + fib_rec(n-2);
}

int fib_line(int n){
    int first = 0;
    int second = 1;
    int t = 1;
    for(int i=0; i<n; i++){
        t = first + second;
        first = second;
        second = t;
    }

    return t;
}

const int value = 20;

int main(){



    //--- recursive
    printf("fib recursive: \n");
    for(int i =0; i<value; i++){
        printf("%d ", fib_rec(i));    
    }
    printf("\n\n");


    //--- line
    printf("fib line: \n");
    for(int i =0; i<value; i++){
        printf("%d ", fib_line(i));    
    }
    printf("\n");



    return 0;
}