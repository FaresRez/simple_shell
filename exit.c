#include "shell.h"

/**
 * exit_status - exits the shell with or without a status
 * @args: array of arguments
 */
void exit_status(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
	}
	exit(status);
}
