#include "shell.h"

/**
 * handle_path - checks if the command exists or not and handle's the path
 * @args: array of arguments
 * @input: input by user
 * Return: pointer to the full cmd we need to execute
 */
char *handle_path(char *input)
{
	char *path = NULL, *full_cmd = NULL, *tmp = NULL;
	char *dir = NULL, *path_copy = NULL;
	int i;

	if (input[0] == '/')
	{
		return (input);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		tmp = environ[i];
		if (strncmp(tmp, "PATH=", 5) == 0)
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
	path_copy = strdup(path);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_cmd = malloc(strlen(path) + strlen(input) + 2);
		if (full_cmd == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		sprintf(full_cmd, "%s/%s", dir, input);
		if (access(full_cmd, X_OK) == 0)
		{
			free(path_copy);
			return (full_cmd);
		}

		free(full_cmd);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	printf("%s: Command not found\n", input);
	return (NULL);
}
