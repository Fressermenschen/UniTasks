//for some reason Clion passes a corruted stack error with 50 and 100 frames, but the programm runs normally despite that

#include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], position = 0;

    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            position = i;
        }
    }
    return position;
}

int main()
{
    int num_of_frames, num_of_pages, frames[1000], pages[1000], counter = 0, time[10], flag1, flag2, i, j, position, misses = 0, hits;
    num_of_pages = 1000;

    printf("Enter the number of frames: ");
    scanf("%d", &num_of_frames);

    FILE *ptr;
    ptr = freopen("Lab 09 input.txt","r", stdin);

    if (ptr ==  NULL) {
        printf("File not found");
        return 1;
    }

    int temp;
    i = 0;

    while(scanf("%d", &temp) != EOF) {
        pages[i] = temp;
        i++;
    }

    for (i = 0; i < num_of_frames; ++i) {
        frames[i] = -1;
    }

    for (i = 0; i < num_of_pages; ++i) {
        flag1 = flag2 = 0;

        for (j = 0; j < num_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (j = 0; j < num_of_frames; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    misses++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            position = findLRU(time, num_of_frames);
            counter++;
            misses++;
            frames[position] = pages[i];
            time[position] = counter;
        }
    }

    printf("Miss: %d\n", misses);
    hits = num_of_pages - misses;
    printf("Hit/Miss Ratio: %d/%d", hits, misses);

    return 0;
}
