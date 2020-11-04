#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
        char output[20];
        int fd = open("/dev/urandom", O_RDONLY);
        read(fd, output, 20);
        close(fd);
        int fs = open("../week12/ex1.txt", O_RDWR | O_CREAT);
        write(fs, output, sizeof(output)/sizeof(char));
        close(fs);
        return 0;
}
