#include <stdio.h>
#include <pthread.h>





void *worker(void *inparams){
    int *params = (int *)inparams;
    
    printf("hello [%d] - from thread: %d\n", *params, (int)pthread_self());
    // printf("hello - from thread: %d\n", (int)pthread_self());

}

int main(){

    pthread_t ts[10];
    
    

    for(int i=0; i<10;i++){
        // pthread_t t;
        // pthread_create(&t, NULL, worker, NULL);
        // ts[i] = t;
        pthread_create(&ts[i], NULL, worker, (void*)&i);
        // pthread_create(&ts[i], NULL, worker, NULL);
    }
    
    for(int i=0; i<10;i++){

        pthread_join(ts[i], NULL);
    }



    printf("main finish \n");
    return 0;
}