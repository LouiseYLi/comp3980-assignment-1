#include "../include/readWrite.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum
{
    BUFFER_SIZE = 128
};

int readFd(int fdRead)
{
    char    buffer[BUFFER_SIZE];
    ssize_t bytes_read = read(fdRead, buffer, sizeof(buffer) - 1);
    if(bytes_read == -1)
    {
        return -1;
    }
    buffer[bytes_read] = '\0';
    printf("Read: %s\n", buffer);
    return 0;
}

int writeFd() {

    return 0;
}
