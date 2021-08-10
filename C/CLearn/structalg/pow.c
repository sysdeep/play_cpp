#include <stdio.h>


int fast_pow(int a, int n){
    if(n == 0)
        return 1;
    if(n%2 == 0){
        int b = fast_pow(a, n/2);
        return b*b;
    }else{
        return fast_pow(a, n-1)*a;
    }
}


int main(){


    printf("pow 2^2: %d\n", fast_pow(2,2));
    printf("pow 2^3: %d\n", fast_pow(2,3));
    printf("pow 2^4: %d\n", fast_pow(2,4));
    printf("pow 2^5: %d\n", fast_pow(2,5));
    printf("pow 2^6: %d\n", fast_pow(2,6));

    return 0;
}