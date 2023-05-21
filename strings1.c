#include "shell.h"

/**
 * _strlen - counts the length of a string
 * @str: string to measure
 * Return: length of string
 */
int _strlen(const char *str)
{
	int j;

	for (j = 0; str[j] != '\0'; j++)
		;
	return (j);
}
/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 0 if they are the same
 * > 0 if first non matching char in s1 is bigger than that in s2
 * < 0 if opposite
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
/**
 * _strcpy - copy string into other string
 * @from: string to copy
 * @to: the created copy
 */
void _strcpy(char *to, char *from)
{
	int j = 0;

	while (from[j] != '\0')
	{
		to[j] = from[j];
		j++;
	}
	to[j] = '\0';
}
/**
 * _strdup - created a duplicate of a string using malloc
 * @s: string to duplicate
 * Return: pointer to the newly allocated string dup
 */
char *_strdup(const char *s)
{
	size_t j;
	size_t len = _strlen(s) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < len; j++)
	{
		new_str[j] = s[j];
	}
	return (new_str);
}

