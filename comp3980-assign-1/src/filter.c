#include "../include/filter.h"
#include "../include/display.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// enum
// {
//     MAX_LENGTH = 5
// };

void filter(const char *msg)
{
    printf("%s\n", msg);
}

char upper(char c)
{
    return (char)toupper((unsigned char)c);    // ensures no negative vals avoids errors
}

char lower(char c)
{
    return (char)toupper((unsigned char)c);
}

char null(char c)
{
    return c;
}

// returns 0 if invalid argument, otherwise will return u | l | n
char checkFilterArgs(const char *arg)
{
    char result = '0';
    if(arg == NULL)
    {
        perror("Error: argument is null.");
        return result;
    }
    if(strcmp(arg, "upper") == 0)
    {
        result = 'u';
    }
    else if(strcmp(arg, "lower") == 0)
    {
        result = 'l';
    }
    else if(strcmp(arg, "null") == 0)
    {
        result = 'n';
    }
    return result;
}
