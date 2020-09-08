/*
Each time the programm is ran it outputs a different set of values. This happens because with each run a new process is created, same can be said about forking a new process
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int n = 10;
    int pid = fork();
    if (pid > 0) {
        printf("Hello from parent [%d - %d]\n", pid, n);
    } else if (pid == 0) {
    printf("Hello from child [%d - %d]\n", pid, n);
    }
    return 0;
}
