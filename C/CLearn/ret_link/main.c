/*
    возврат ссылки из функции


    в C нет типа данных - ссылка))
*/
#include <stdio.h>



int *foo(int *value){
    (*value)++;
    return value;
}


int main(){

    int a, b;
    int *pb;

    a = 1;

    pb = foo(&a);
    b = *pb;




    printf("a: %d\n", a);
    printf("pb: %ld\n", pb);
    printf("b: %d\n", b);

    return 0;
}