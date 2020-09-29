#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    printf("Input array size \n");
    scanf("%d", &N);
    int *array = malloc(N*sizeof(int));
    printf("Memory allocted \n");
    printf("Array:\n");
    for (int i = 0; i < N; i++) {
        array[i] = i;
        printf("%d ", array[i]);
    }
    free(array);
    printf("\nMemory deallocated\n");
    return 0;
}
