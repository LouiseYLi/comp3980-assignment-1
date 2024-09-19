#include "../include/display.h"
#include "../include/filter.h"
#include "../include/readWrite.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef char (*filterChar)(char);

int main(int argc, char *argv[])
{
    int         fdRead         = -1;
    int         fdWrite        = -1;
    filterChar  filterFunction = null;
    char        currentChar;
    int         option;
    const char *fin  = "0";
    const char *fout = "0";
    while((option = getopt(argc, argv, ":i:o:f:")) != -1)
    {
        switch(option)
        {
            case 'i':
                fin = optarg;
                break;
            case 'o':
                fout = optarg;
                break;
            case 'f':
                filterFunction = checkFilterArgs(optarg);
                break;
            default:
                perror("Error: invalid option(s) entered to command line.");
                return EXIT_FAILURE;
        }
    }
    if(filterFunction == NULL)
    {
        perror("Error: invalid filter type.");
        return EXIT_FAILURE;
    }
    if(strcmp(fin, "0") == 0 || strcmp(fout, "0") == 0)
    {
        return EXIT_FAILURE;
    }
    fdRead  = open(fin, O_CREAT | O_RDONLY | O_CLOEXEC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    fdWrite = open(fout, O_CREAT | O_WRONLY | O_TRUNC | O_CLOEXEC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    // while get eachchar until eof, we transform and write
    while((currentChar = readFd(fdRead, filterFunction)) != EOF)
    {
        if(writeFd(fdWrite, currentChar) == -1)
        {
            perror("Error: error writing to file.");
            return EXIT_FAILURE;
        }
    }

    if(close(fdRead) == -1 || close(fdWrite) == -1)
    {
        perror("Error: error closing file descriptor.");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
