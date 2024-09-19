#include "../include/filter.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef char (*filterChar)(char);

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
    return (char)tolower((unsigned char)c);
}

char null(char c)
{
    return c;
}

filterChar checkFilterArgs(const char *arg)
{
    filterChar filterFunction = NULL;
    if(arg == NULL)
    {
        perror("Error: argument is null.");
        return filterFunction;
    }
    if(strcmp(arg, "upper") == 0)
    {
        filterFunction = upper;
    }
    else if(strcmp(arg, "lower") == 0)
    {
        filterFunction = lower;
    }
    else if(strcmp(arg, "null") == 0)
    {
        filterFunction = null;
    }
    return filterFunction;
}
