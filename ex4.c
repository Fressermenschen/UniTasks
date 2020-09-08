#include <stdio.h>
#include <stdlib.h>

void main() {
	char a[100];
	while(1) {
		fgets(a, 100, stdin);
		char *args[100];		
		int k = 0, i = 0, j = 0;
		for (i = 0; i < 100; i++) {
			args[i] = NULL;
		}
		i = 0;
		args[0] = (char*)malloc(100);	
		while(1) {
			if (a[i] != ' ' && a[i] != '\n' && a[i] != '\0') {
				args[k][j] = a[i];
				i++;
				j++;
			} else if (a[i] == ' ') {
				i++; 
				k++;
				j = 0; 
				args[k] = (char*)malloc(100);
			} else {
				break;
			}
		}
		int pid = fork();
		if (pid == 0) {
			execvp(args[0], args, NULL);
		}
	}
}
