#include "../include/readWrite.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int writeFd(int fdWrite, const char *data)
{
    ssize_t bytes_written = write(fdWrite, data, strlen(data));
    if(bytes_written == -1)
    {
        return -1;
    }
    printf("Written: %s\n", data);

    return 0;
}
