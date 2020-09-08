/*
3 fork() - 8 processes
5 fork() - 32 processes
Process with n forks executes processes with n-1, n-2 ..., n-n forks.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	for(i=0;i<5;i++){
		fork();
	}
	sleep(5);
	return 0;
}
