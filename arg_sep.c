#include "shell.h"

/**
 * argument_sep - seperates the command retrieved by getline
 * into seperate arguments
 * @cmd: command retrieved by getline
 * Return: the array of pointers to arguments
 */
char **arg_sep(char *cmd)
{
	int num_args = 0;
	char *token;
	static char *args[512];

	token = strtok(cmd, " \n");
	while (token != NULL)
	{
		args[num_args] = token;
		num_args++;
		token = strtok(NULL, " \n");
	}
	args[num_args] = NULL;
	return (args);
}
