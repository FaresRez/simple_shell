#include "shell.h"
/**
 * handle_path - checks if the command exists or not and handle's the path
 * @input: input by user
 * Return: pointer to the full cmd we need to execute with absolute path
 */
char *handle_path(char *input)
{
	char *path = NULL, *full_cmd = NULL, *tmp = NULL;
	char *dir = NULL, *path_copy = NULL;
	int j;

	if (input[0] == '/')
		return (input);
	for (j = 0; environ[j] != NULL; j++)
	{
		tmp = environ[j];
		if (_strncmp(tmp, "PATH=", 5) == 0)
		{
			path = tmp + 5;
			break;
		}
	}
	if (path == NULL)
	{
		perror("environ");
		return (NULL);
	}
	path_copy = _strdup(path);
	dir = _strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_cmd = malloc(_strlen(path) + _strlen(input) + 2);
		if (full_cmd == NULL)
			return (NULL);
		_strcpy(full_cmd, dir);
		_strcat(full_cmd, "/");
		_strcat(full_cmd, input);
		if (access(full_cmd, X_OK) == 0)
		{
			free(path_copy);
			return (full_cmd);
		}
		free(full_cmd);
		dir = _strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
