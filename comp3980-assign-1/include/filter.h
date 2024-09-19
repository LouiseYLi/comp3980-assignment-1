#ifndef PROGRAMMING101_FILTER_H
#define PROGRAMMING101_FILTER_H

typedef char (*filterChar)(char);

char       upper(char c);
char       lower(char c);
char       null(char c);
filterChar checkFilterArgs(const char *arg);

#endif
