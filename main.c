#include "shell.h"
/**
 * main - a simple shell program
 * @ac: number of arguments inputted at command line
 * @av: array of arguments
 * Return: 0 success
 */
int main(__attribute__((unused)) int ac, char *av[])
{
	size_t n = 0;
	char *input = NULL, **args;
	ssize_t read;
	int interactive = isatty(STDIN_FILENO);

	if (interactive)
	{
		while (1)
		{
			write(1, "myShell$ ", 9);
			read = getline(&input, &n, stdin);
			if (read == -1)
			{
				write(1, "\n", 1);
				free(input);
				exit(0);
			}
			input[read - 1] = '\0';
			args = arg_sep(input);
			if (args[0] == NULL)
				continue;
			if (built_in_parser(args, input) == 0)
				continue;
			execmd(args, av, 1);
		}
	}
	else
	{
		while (getline(&input, &n, stdin) > 0)
		{
			args = arg_sep(input);
			if (args[0] == NULL)
				continue;
			if (built_in_parser(args, input) == 0)
				continue;
			execmd(args, av, 0);
		}
		free(input);
	}
	return (0);
}
