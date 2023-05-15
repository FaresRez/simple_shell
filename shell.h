#ifndef _shell_h
#define _shell_h
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
int execmd(char **args, char *av[], int i);
char **arg_sep(char *cmd);
void exit_status(char **args);
#endif
