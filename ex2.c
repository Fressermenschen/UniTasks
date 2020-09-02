#include <stdio.h>

void bubble_sort(int array[], int size) {
    int temp;
    for (int j = 0; j < size - 1; j++) {
        for (int i = 0; i < size - j - 1; i++) {
            if (array[i + 1] < array[i]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
    printf("Sorted Array\n");
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
}

int main(){
    printf("Enter number of elements\n");
    int n;
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
    int a[100];
    for (int i = 0; i < n; i++){
         scanf("%d", &a[i]);
    }
    bubble_sort(a, n);
    return 0;
}
