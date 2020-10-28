//Output file "ex1.memcpy.txt" needs to be created beforehand

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

void main() {
    int fs = open("../week11/ex1.txt", O_RDWR);
    if (fs == -1) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    
    struct stat st;
    stat("ex1.txt", &st);
    size_t insize = st.st_size;
    void *in = NULL;
    in = mmap( NULL, insize, PROT_WRITE | PROT_READ, MAP_SHARED, fs, 0 );
    char *text = in;
    int fd = open("ex1.memcpy.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    
    size_t textsize = strlen(text) + 1;
    lseek(fd, textsize-1, SEEK_SET);
    write(fd, "", 1);
    char *map = mmap(0, textsize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    for (size_t i = 0; i < textsize; i++)
        map[i] = text[i];

    msync(map, textsize, MS_SYNC);
    munmap(map, textsize);
    close(fd);
}
