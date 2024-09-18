#include "../include/readWrite.h"
#include "../include/display.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char readFd(int fdRead)
{
    char    buffer;
    ssize_t bytes_read = read(fdRead, &buffer, sizeof(buffer) - 1);
    if(bytes_read == -1)
    {
        perror("Error: could not read file.");
        return EXIT_FAILURE;
    }
    // buffer[bytes_read] = '\0';
    printf("Read: %c\n", buffer);
    return buffer;
}

int writeFd(int fdWrite, const char c)
{
    ssize_t bytes_written = write(fdWrite, &c, 1);
    if(bytes_written == -1)
    {
        return -1;
    }
    printf("Written: %c\n", c);

    return 0;
}
