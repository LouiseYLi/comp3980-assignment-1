#ifndef PROGRAMMING101_READWRITE_H
#define PROGRAMMING101_READWRITE_H
typedef char (*filterChar)(char);

char readFd(int fdRead, filterChar filterFunction);

int writeFd(int fdWrite, char c);

#endif
