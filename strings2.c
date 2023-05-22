#include "shell.h"

/**
 * _strcat - Entry point
 * @dest: pointer to the destination
 * @src: pointer to the source
 * Return: pointer to a character
 */

char *_strcat(char *dest, const char *src)
{
	char *dest_ptr = dest;

	while (*dest_ptr != '\0')
	{
		dest_ptr++;
	}

	while (*src != '\0')
	{
		*dest_ptr++ = *src++;
	}
	*dest_ptr = '\0';

	return (dest);

}

/**
 * _strchr - Entry point
 * @k: string
 * @c: charachter
 * Return: pointer to a character
 */

char *_strchr(const char *k, int c)
{
	while (*k != '\0')
	{
		if (*k == c)
		{
			return ((char *)k);
		}
		k++;
	}
	if (c == '\0')
	{
		return ((char *)k);
	}
	return (NULL);
}
/**
 * _atoi - convert string to int
 * @str: string
 * Return: int
 */
int _atoi(const char *str)
{
	int res = 0;
	int sign = 1;
	int j = 0;

	if (str[0] == '+' || str[0] == '-')
	{
	if (str[0] == '-')
		sign = -1;
	j++;
	}
	while (str[j] != '\0')
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			res = res * 10 + (str[j] - '0');
			j++;
		}
		else
			break;
	}

	return (res * sign);
}

/**
 * _strncmp - compares n characters of two strings
 * @str1: first string
 * @str2: second string
 * @n: number of chars to compare
 * Return: 0 on success
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t j;

	for (j = 0; j < n; j++)
	{
		if (str1[j] != str2[j])
			return (str1[j] - str2[j]);
		else if (str1[j] == '\0')
			return (0);
	}

	return (0);
}
