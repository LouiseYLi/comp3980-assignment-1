#include "../include/display.h"
#include "../include/filter.h"
#include "../include/readWrite.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

enum
{
    TEMP = 6
};

int main(int argc, char *argv[])
{
    char string[TEMP];    // 5 characters + 1 for null terminator
    // const long unsigned int TEMP_BYTES = 10;
    int option;
    int fdRead  = -1;
    int fdWrite = -1;
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

    while((option = getopt(argc, argv, "i:o:f:")) != -1)
    {
        switch(option)
        {
            case 'i':
                display("Option -i");
                fdRead = open(optarg, O_CREAT | O_RDONLY | O_CLOEXEC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
                if(fdRead == -1)
                {
                    display("Error: unable to open input file.");
                    return EXIT_FAILURE;
                }
                break;
            case 'o':
                display("Option -o");
                display(optarg);
                fdWrite = open(optarg, O_CREAT | O_WRONLY | O_CLOEXEC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
                if(fdWrite == -1)
                {
                    display("Error: unable to open output file.");
                    close(fdRead);
                    return EXIT_FAILURE;
                }
                break;
            case 'f':
                display("Option -f");
                break;
            default:
                display("Error: invalid option(s) entered to command line.");
                close(fdRead);
                close(fdWrite);
                // free(inputFile);
                // free(outputFile);
                // if(close(fdRead) == -1)
                // {
                //     display("Error: error closing file descriptor.");
                //     return EXIT_FAILURE;
                // }
                return EXIT_FAILURE;
        }
    }
    readFd(fdRead);

    strcpy(string, "MELL");
    writeFd(fdWrite, string);
    // loop to check argc
    // for(int i = 0; i < argc; i++)
    // {
    //     display(argv[i]);
    //     displayInt(i);
    //     display("end of loop");
    // }
    // if(close(fd) == -1)
    // {
    //     display("Closed file descriptor.");
    //     return EXIT_SUCCESS;
    // }
    // if(close(fdRead) == -1)
    // {
    //     display("Error: error closing file descriptor.");
    //     return EXIT_FAILURE;
    // }
    filter("Cool cats 111");
    // free(inputFile);
    // free(outputFile);
    return EXIT_SUCCESS;
}
