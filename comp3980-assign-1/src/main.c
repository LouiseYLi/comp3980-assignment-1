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
    const int  TOTAL_ARGUMENTS = 7;
    int        fdRead          = -1;
    int        fdWrite         = -1;
    filterChar filterFunction  = null;
    char       currentChar;
    int        option;
    if(argc != TOTAL_ARGUMENTS)
    {
        perror("Error: Invalid number of arguments.");
        return EXIT_FAILURE;
    }
    while((option = getopt(argc, argv, "i:o:f:")) != -1)
    {
        switch(option)
        {
            case 'i':
                fdRead = open(optarg, O_CREAT | O_RDONLY | O_CLOEXEC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
                if(fdRead == -1)
                {
                    perror("Error: unable to open input file.");
                    return EXIT_FAILURE;
                }
                break;
            case 'o':
                fdWrite = open(optarg, O_CREAT | O_WRONLY | O_TRUNC | O_CLOEXEC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
                if(fdWrite == -1)
                {
                    perror("Error: unable to open output file.");
                    close(fdRead);
                    return EXIT_FAILURE;
                }
                break;
            case 'f':
                filterFunction = checkFilterArgs(optarg);
                break;
            default:
                perror("Error: invalid option(s) entered to command line.");
                if(close(fdRead) == -1 || close(fdWrite) == -1)
                {
                    perror("Error: error closing file descriptor.");
                    return EXIT_FAILURE;
                }
                return EXIT_FAILURE;
        }
    }
    // while get eachchar until eof, we transform and write
    while((currentChar = readFd(fdRead, filterFunction)) != EOF)
    {
        writeFd(fdWrite, currentChar);
    }

    if(close(fdRead) == -1 || close(fdWrite) == -1)
    {
        perror("Error: error closing file descriptor.");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

// char string[TEMP];
// strcpy(string, "MELL");

// const long unsigned int TEMP_BYTES = 10;

// fd = open(optarg, O_RDONLY);
//     if(fd == -1)
// {
//     display("Error: unable to open file.");
//     exit(EXIT_FAILURE);
// }
// int filter;
// char *inputFile;
// char *outputFile;
// inputFile = (char *)malloc(TEMP_BYTES * sizeof(char));
// if(inputFile == NULL)
// {
//     display("Error: memory allocation failed for inputFile.");
//     return EXIT_FAILURE;
// }
// outputFile = (char *)malloc(TEMP_BYTES * sizeof(char));
// if(outputFile == NULL)
// {
//     display("Error: memory allocation failed for outputFile.");
//     free(inputFile);
//     return EXIT_FAILURE;
// }
// switch to assign filter function
// switch(filterType)
// {
//     case 'u':
//         filterFunction = upper;
//         break;
//     case 'l':
//         filterFunction = lower;
//         break;
//     case 'n':
//         filterFunction = null;
//         break;
//     default:
//         perror("Error: invalid filterType entered to command line.");
//         if(close(fdRead) == -1 || close(fdWrite) == -1)
//         {
//             perror("Error: error closing file descriptor.");
//             return EXIT_FAILURE;
//         }
//         return EXIT_FAILURE;
// }
