#include "shell.h"

/**
 * arg_sep - seperates the command retrieved by getline
 * into seperate arguments
 * @input: command retrieved by getline
 * Return: the array of pointers to arguments
 */
char **arg_sep(char *input)
{
	int args_num = 0;
	char *token;
	static char *args[250];

	token = _strtok(input, " \n\t\r");
	while (token != NULL)
	{
		args[args_num] = token;
		args_num++;
		token = _strtok(NULL, " \n\t\r");
	}
	args[args_num] = NULL;

	return (args);
}
