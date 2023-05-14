#ifndef _shell_h
#define _shell_h
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
int execmd(char *cmd, char *av[], int i);
#endif
