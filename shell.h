#ifndef _shell_h
#define _shell_h

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

void execmd(char **args, char *av[], char *input, int i);
char **arg_sep(char *input);
void exit_status(char **args);
int access_cmd(char *path, char **args, char *full_cmd);
char *handle_path(char *input);
void error_msg(char *av[], char **args, int i, int n);

#endif
