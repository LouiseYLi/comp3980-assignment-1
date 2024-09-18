#include "../include/readWrite.h"
#include "../include/display.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char readFd(int fdRead)
{
    char    c;
    ssize_t bytes_read = read(fdRead, &c, 1);
    if(bytes_read == -1)
    {
        perror("Error: could not read file.");
        return EXIT_FAILURE;
    }
    // c[bytes_read] = '\0';
    printf("Read: %c\n", c);
    return c;
}

int writeFd(int fdWrite, const char c)
{
    ssize_t bytes_written = write(fdWrite, &c, 1);
    if(bytes_written == -1)
    {
        perror("Error: could not read file.");
        return EXIT_FAILURE;
    }
    printf("Written: %c\n", c);

    return 0;
}
