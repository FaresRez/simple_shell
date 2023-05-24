#include "shell.h"

/**
 * exit_status - exits the shell with or without a status
 * @args: array of arguments
 * @input: command input
 * Return: 0
 */
int exit_status(char **args, char *input)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
	}
	free(input);
	exit(status);
	return (0);
}
