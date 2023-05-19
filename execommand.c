#include "shell.h"
/**
 * error_msg - prints to stderr the error msg depending on mode
 * @av: array of args passed at command line
 * @args: array of tokenized input
 * @i: mode (interactive or non interactive)
 * @n: int to defferenciate where we are
 */
void error_msg(char *av[], char **args, int i, int n)
{
	if (!i)
	{
		write(2, av[0], strlen(av[0]));
		write(2, ": 1: ", 5);
		write(2, args[0], strlen(args[0]));
		write(2, ": not found\n", 12);
	}
	else
	{
		if (n == 1)
		{
			write(2, args[0], strlen(args[0]));
			write(2, ": Command not found\n", 20);
		}
		else if (n == 2)
		{
			write(2, "-hsh: ", 6);
			perror(args[0]);
		}
	}
}
/**
 * execmd - executes the command
 * @args: array of tokenized arguments
 * @av: array of strings input into command line
 * @input: input string from user
 * @i: mode specifier (can be either 1 or 0)
 */
void execmd(char **args, char *av[], char *input, int i)
{
	pid_t pid;
	int stat;
	char *full_cmd;

	if (strcmp(args[0], "exit") == 0)
	{
		free(input);
		exit_status(args);
	}
	full_cmd = handle_path(args[0]);
	if (full_cmd == NULL)
	{
		error_msg(av, args, i, 1);
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		execve(full_cmd, args, environ);
		error_msg(av, args, i, 2);
	}
	else if (pid > 0)
	{
		if (strlen(full_cmd) != strlen(args[0]))
			free(full_cmd);
		waitpid(pid, &stat, 0);
	}
	else
		write(2, "fork failed", 11);
}
