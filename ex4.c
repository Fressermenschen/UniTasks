#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

void main(){
        for (int i = 0; i < 10; i++) {
                int* ptr = malloc(10*1024*1024);
                memset(ptr,0,10*1024*1024);
                struct rusage usage;
                getrusage(RUSAGE_SELF, &usage);
                printf("%d\n",usage.ru_maxrss);
                sleep(1);
        }
}
