#include "../include/filter.h"
#include <ctype.h>
#include <stdio.h>

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

// int checkFilterArgs(const char *msg)
// {
//     char upper[MAX_LENGTH];
//     strcpy(upper, "upper")
//     return 0;
// }
