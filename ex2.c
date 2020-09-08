/*
3 fork() - 8 processes
5 fork() - 32 processes
Process with n fork-s, executes processes with n-1, n-2 ...,0 fork-s.
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
