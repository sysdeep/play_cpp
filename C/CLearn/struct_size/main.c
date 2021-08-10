/*
    выравнивание в структуре

    char + char + int + char = 1 + 1 + 4 + 1 = 7
    real = 1 + 1 + 2pad + 4 + 1 + 3pad = 12

    выравнивание происходит по самому большому элементу

    1 + 1 = 2, а макс. 4 - то 1 + 1 дополняются отступом справа до макс
*/
#include <stdio.h>


typedef struct foo{
    char a;             // 1
    char b;             // 1
    int i;              // 4
    char c;             // 1
} foo;


int main(){

    foo a;

    printf("char: %ld\n", sizeof(char));
    printf("int: %ld\n", sizeof(int));
    printf("my struct: %ld\n", sizeof(foo));


    return 0;
}