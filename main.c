#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <unistd.h>

#define THREADS_NR 9

void *hello(void *arg) {
// Write function which display a message hello (TID value): : (numer_TID)
// and returing a status  with a value equal to the argument passed to the function
    long tid;
    int* returned_value = malloc(sizeof(int));
    *returned_value = *(int*)arg;
    tid = (long) arg;
    printf("hello %i : : %ld returned_value = %i \n",*(int*)arg,tid, *returned_value);


    pthread_exit(returned_value);




//end
}

int main(int argc, char* argv[]) 
{
    pthread_t hello_threads[THREADS_NR];
    int *count = malloc(sizeof(int));
    int i;

    for (i=0; i<THREADS_NR;i++) {
     *count=i+1;
     int result = pthread_create(&hello_threads[i], NULL, hello, (void *) count);
     if (result != 0) {
         perror("Could not create thread.");
         }
     usleep(1000);

     }
    int* hello_results[THREADS_NR];


    for (int i = 0; i < THREADS_NR; i++)
    {
        pthread_join(hello_threads[i], (void*)&hello_results[i]);
         
        //printf("Thread (%d) TID: (%ld) returned value: (%i) \n",i,(long)hello_threads[i], *hello_results[i] );
    }

    for (int i = 0; i < THREADS_NR; i++)
    {
        //pthread_join(hello_threads[i], &hello_results[i]);
         
        printf("Thread (%d) TID: (%ld) returned value: %i \n",i,(long)hello_threads[i], *hello_results[i] );
    }
// Wait for ending of THREADS_NR threads, get status of ending,  store it in hello_result
// and display it on the screen: Thread (index of thread+1) TID: (nr_TID) returned value: (status of thread ending) 



//end
    return 0;
}
