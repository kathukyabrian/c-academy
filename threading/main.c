#include <stdlib.h>
#include <stdio.h>

// for threading purposes
#include <pthread.h>

// define a variable for locking purposes
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// reference: https://www.javatpoint.com/multithreading-in-c

void *run_in_thread(){
    pthread_mutex_lock(&mutex);
    printf("This is from a thread\n");

    // multi-threading has its own challenges 
    // 1 of the challenges is race condition
    // race condition happens when 2 threads access the same resource at the same time
    // an example is an ATM machine where a deposit and withdrawal happens at the same time
    // this problem can be solved by locking a certain block of code such that only one thread can access that block at a time

    pthread_mutex_unlock(&mutex);
}

int main(){
    pthread_t thread_id;

    /*
        function to create thread - expects 4 arguments
        1. thread_id
        2. attributes
        3. routine to be executed
        4. arguments to be passed to the routine
    */
    pthread_create(&thread_id, NULL, run_in_thread, NULL);
    // pthread_join(thread_id, NULL);

    printf("This is getting executed simultaneously, this can be blocked by thread join()\n");

    return EXIT_SUCCESS;   
}
