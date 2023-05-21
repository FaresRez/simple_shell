#include "shell.h"

/**
 * get_env - gets the environment var specified (replaces getenv)
 * Return: char pointer to the env variable we want
 * @var_name: name of the env variable
 */

char *get_env(char *var_name)
{
	int i;
	char *tmp = NULL, *env_var = NULL, *full_name = NULL;

	full_name = malloc(_strlen(var_name) + 2);
	_strcpy(full_name, var_name);
	_strcat(full_name, "=");

	for (i = 0; environ[i] != NULL; i++)
	{
		tmp = environ[i];
		if (_strncmp(tmp, full_name, _strlen(full_name)) == 0)
		{
			env_var = tmp + _strlen(full_name);
			break;
		}
	}

	free(full_name);
	return (env_var);
}
