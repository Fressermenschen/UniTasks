// This code was written with assumption that all arrival times are equal, as it doesn't seem effecient to use this sorting method if it is not the case

#include <stdio.h>

void main()
{
    int n, count, CT, TAT, WT; 
    float ATAT, AWT;
    AWT = 0;
    ATAT = 0;
    count = 0;
    printf("Input the number of programs\n");
    scanf("%d", &n);
    int array[n][2];
    int array2[n][2];
    for (int i = 0; i < n; i++) {
        printf("Input burst time[%d]:\n", i);
        scanf("%d", &array[i][1]);
        array[i][0] = 0;
    }
    

    int tmp1, tmp2;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (array[i][1] > array[j][1]) {
                tmp1 = array[i][0];
                tmp2 = array[i][1];
                array[i][0] = array[j][0];
                array[i][1] = array[j][1];
                array[j][0] = tmp1;
                array[j][1] = tmp2;
            }
        }   
    }
    
    printf ("№  AT  BT  CT  TAT  WT\n\n");
    
    for (int i = 0; i < n; i++) {
        if (array[i][0] > count) {
            CT = array[i][0] + array[i][1];
        } else {
            CT = array[i][1] + count;
        }
        count = CT;
        TAT = CT - array[i][0];
        WT = TAT - array[i][1];
        array2[i][0] = TAT;
        array2[i][1] = WT;
        printf("%d  %d  %d  %d  %d  %d \n\n", i, array[i][0], array[i][1], CT, TAT, WT);
    }
    for (int i = 0; i < n; i++) {
        AWT +=  array2[i][1];
        ATAT += array2[i][0];
    }
    AWT = AWT/n;
    ATAT = ATAT/n;
    printf("Average TAT: %f\n", ATAT);
    printf("Average AWT: %f\n", AWT);
}
