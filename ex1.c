#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 3 //Number of threads that will be created

// Thread funcion
void *output(void *num)
{
    int i = (int*)num;
    printf("I'm thread %d\n", i);
}


int main()
{
    pthread_t thread;
    
    for (int i = 0; i < N; ++i) {
        pthread_create(&thread, NULL, output, (void*) i);
        printf("%s \n", "Thread created");
    }
    pthread_exit(NULL);
}
