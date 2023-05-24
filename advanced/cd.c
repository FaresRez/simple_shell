#include "shell.h"
/**
 * my_cd - changes the directory
 * @args: array of tokenized strings from input
 * Return: 0 on success, 1 on failure
 */
int my_cd(char **args, __attribute__((unused)) char *input)
{
	char *home = get_env("HOME");
	static char *prev_dir, *curr_dir;
	char *dir[2];

	if (args[1] == NULL)
	{
		dir[0] = home;
		curr_dir = getcwd(NULL, 0);
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		if (prev_dir != NULL)
			dir[0] = prev_dir;
		else
		{
			write(1, "./hsh: cd: OLDPWD not set\n", 26);
			return (1);
		}
	}
	else
	{
		dir[0] = args[1];
		curr_dir = getcwd(NULL, 0);
	}
	dir[1] = NULL;
	prev_dir = curr_dir;
	curr_dir = getcwd(NULL, 0);
	if (chdir(dir[0]) != 0)
	{
		perror("cd");
		return (1);
	}
	else
	{
		setenv("PWD", getcwd(NULL, 0), 1);
		return (0);
	}
	return (0);
}
