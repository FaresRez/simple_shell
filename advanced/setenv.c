#include "shell.h"

/**
 * my_setenv - sets and unsets env variables
 * @args: array of tokenized strings from input
 * Return: 1 on success, 0 on error
 */
int my_setenv(char **args, __attribute__((unused)) char *input)
{
	int j, set;

	for (j = 0; args[j] != NULL; j++)
		;
	if (j < 2)
	{
		write(2, "Usage: VARIABLE [VALUE]\n", 24);
		return (0);
	}
	if (_strcmp(args[0], "setenv") == 0)
	{
		if (j < 3)
		{
			write(2, "Usage: setenv VARIABLE VALUE\n", 29);
			return (0);
		}
		set = setenv(args[1], args[2], 1);
		if (set)
			perror("setenv");
		return (0);
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		set = unsetenv(args[1]);
		if  (set)
			perror("unsetenv");
		return (0);
	}
	return (1);
}
