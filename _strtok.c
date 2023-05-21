#include "shell.h"

/**
 * _strtok - tokenizes strings in c
 * @str: string to tokenize
 * @delim: delimeter or token seperator
 * Return: pointer to token or NULL if there are no more strings
 */
char *_strtok(char *str, const char *delim)
{
	static char *saved;
	char *token = NULL;

	if (str)
		saved = str;

	if (saved == NULL)
		return (NULL);

	while (*saved != '\0' && _strchr(delim, *saved) != NULL)
	{
		saved++;
	}

	token = saved;
	while (*saved != '\0')
	{
		if (_strchr(delim, *saved) != NULL)
		{
			*saved = '\0';
			saved++;

			while (*saved != '\0' && _strchr(delim, *saved) != NULL)
			{
				saved++;
			}
			return (token);
		}
		saved++;
	}

	if (token == saved)
		return (NULL);
	return (token);
}

