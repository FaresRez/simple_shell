#ifndef _shell_h
#define _shell_h

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

char *_strdup(const char *s);
void _strcpy(char *to, char *from);
int _strcmp(char *str1, char *str2);
int _strlen(const char *str);
char *_strchr(const char *k, int c);
char *_strtok(char *str, const char *delim);
int _atoi(const char *str);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcat(char *dest, const char *src);
void execmd(char **args, char *av[], char *input, int i);
char **arg_sep(char *input);
void exit_status(char **args);
int access_cmd(char *path, char **args, char *full_cmd);
char *handle_path(char *input);
void error_msg(char *av[], char **args, int i, int n);
char *get_env(char *var_name);
int my_cd(char **args);
int cd_checker(char **args);

#endif
