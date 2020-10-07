//swap happened oonly during proccess #1, increasing allocated memory to 1 gb didn't help

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main(){
        for (int i = 0; i < 10; i++) {
                int* ptr = malloc(1*1024*1024*1024);
                memset(ptr,0,1*1024*1024*1024);
                sleep(1);
        }
}
