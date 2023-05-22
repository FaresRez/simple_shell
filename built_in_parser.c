#include "shell.h"

/**
 * built_in_parser - a function that selects other functions
 * depending on command
 * @args: array of tokenized strings from input
 * Return: 0 on success, 1 on error
 */
int built_in_parser(char **args)
{
	int i;

	built_ins func_arr[] = {
		{"cd", my_cd},
		{"setenv", my_setenv},
		{"unsetenv", my_setenv},
		{"exit", exit_status},
		{NULL, NULL}
	};

	for (i = 0; func_arr[i].built_in != NULL; i++)
	{
		if (_strcmp(args[0], func_arr[i].built_in) == 0)
		{
			func_arr[i].func(args);
			return (0);
		}
	}
	return (1);
}
