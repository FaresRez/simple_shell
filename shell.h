#ifndef _shell_h
#define _shell_h

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
extern char **environ;

/**
 * struct built_ins - a structure for built in commands and their functions
 * @built_in: the command
 * @func: the function associated
 */
typedef struct built_ins
{
	char *built_in;
	int (*func)(char **args, char *input);
} built_ins;

/* string manipulation function prototypes */
char *_strdup(const char *s);
void _strcpy(char *to, char *from);
int _strcmp(char *str1, char *str2);
int _strlen(const char *str);
char *_strchr(const char *k, int c);
char *_strtok(char *str, const char *delim);
int _atoi(const char *str);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcat(char *dest, const char *src);
/* shell functions */
char *getcmd(void);
void execmd(char **args, char *av[], int i);
char **arg_sep(char *input);
int access_cmd(char *path, char **args, char *full_cmd);
char *handle_path(char *input);
void error_msg(char *av[], char **args, int i, int n);
char *get_env(char *var_name);
/* built_in commands functions */
int exit_status(char **args, char *input);
int my_cd(char **args, char *input);
int my_setenv(char **args, char *input);
int built_in_parser(char **args, char *input);
#endif
