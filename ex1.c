//This code will write "This is a nice day ^@" I'm unable to remove ^@ as it usually results in code writing only about half of the text

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

void main()
{
    const char *text = "This is a nice day\0";

    const char *filepath = "../week11/ex1.txt";

    int fd = open(filepath, O_RDWR);

    if (fd == -1)
    {
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
