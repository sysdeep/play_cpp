#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define THREADS 10



void *worker(void *inparams){
    int *params = (int *)inparams;
    
    printf("hello [%d] - from thread: %d\n", *params, (int)pthread_self());
    // printf("hello - from thread: %d\n", (int)pthread_self());

	usleep(2 * 1000000);
	printf("thread: %d - finished\n", *params);

}


int main(){

    pthread_t ts[THREADS];
	int threads_params[THREADS];			// save params
    
    

    for(int i=0; i<10;i++){
		threads_params[i] = i;
        pthread_create(&ts[i], NULL, worker, (void*)&threads_params[i]);
    }


    for(int i=0; i<10;i++){
        pthread_join(ts[i], NULL);
    }



    printf("main finish \n");
    return 0;
}