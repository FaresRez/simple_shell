#include "shell.h"

/**
 * built_in_parser - a function that selects other functions
 * depending on command
 * @args: array of tokenized strings from input
 * @input: command input
 * Return: 0 on success, 1 on error
 */
int built_in_parser(char **args, char *input)
{
	int i;

	built_ins func_arr[] = {
		{"exit", exit_status},
		{"setenv", my_setenv},
		{"unsetenv", my_setenv},
		{"cd", my_cd},
		{NULL, NULL}
	};

	for (i = 0; func_arr[i].built_in != NULL; i++)
	{
		if (_strcmp(args[0], func_arr[i].built_in) == 0)
		{
			func_arr[i].func(args, input);
			return (0);
		}
	}
	return (1);
}
