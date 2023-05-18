#include "shell.h"

/**
 * argument_sep - seperates the command retrieved by getline
 * into seperate arguments
 * @cmd: command retrieved by getline
 * Return: the array of pointers to arguments
 */
char **arg_sep(char *input)
{
	int i, num_args = 0;
	char *token;
	static char *args[250];

	token = strtok(input, " \n\t\r");
	while (token != NULL)
	{
		args[num_args] = token;
		num_args++;
		token = strtok(NULL, " \n\t\r");
	}
	args[num_args] = NULL;

	/**for (i = 0; args[i] != NULL; i++)
	{
		strcat(cmd, args[i]);
		strcat(cmd, " ");
	}
	free(input);*/
	if (args[0] == NULL)
		exit(0);
	return (args);
}
