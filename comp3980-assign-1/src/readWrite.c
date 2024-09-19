#include "../include/readWrite.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef char (*filterChar)(char);

char readFd(int fdRead, filterChar filterFunction)
{
    char    c;
    ssize_t bytes_read = read(fdRead, &c, sizeof(char));
    if(bytes_read == -1)
    {
        perror("Error: could not read file.");
        return EOF;
    }
    if(bytes_read == 0)
    {
        return EOF;
    }
    return filterFunction(c);
}

int writeFd(int fdWrite, const char c)
{
    ssize_t bytes_written = write(fdWrite, &c, sizeof(char));
    if(bytes_written == -1)
    {
        perror("Error: could not read file.");
        return EXIT_FAILURE;
    }
    return 0;
}
