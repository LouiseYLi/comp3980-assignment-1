#include "../include/display.h"
#include "../include/filter.h"
#include "../include/readWrite.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // const long unsigned int TEMP_BYTES = 10;
    int option;
    int fdRead = -1;
    //                fd = open(optarg, O_RDONLY);
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
                fdRead = open(optarg, O_CREAT | O_RDONLY | O_CLOEXEC);
                if(fdRead == -1)
                {
                    display("Error: unable to open file.");
                    exit(EXIT_FAILURE);
                }
                break;
            case 'o':
                display("Option -o");
                break;
            case 'f':
                display("Option -f");
                break;
            default:
                display("Error: invalid option(s) entered to command line.");
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
