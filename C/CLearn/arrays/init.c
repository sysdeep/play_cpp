#include <stdio.h>


int main(){

    int a[10] = {};         // init array of 0

    printf("arrays init\n");
    for(int i=0; i<10; i++){
        printf("%d\n", a[i]);
    }

    return 0;
}