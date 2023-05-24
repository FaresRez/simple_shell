#include "shell.h"
/**
 * my_cd - changes the directory
 * @args: array of tokenized strings from input
 * @input: input from user
 * Return: 0 on success, 1 on failure
 */
int my_cd(char **args, __attribute__((unused)) char *input)
{
	char *home = get_env("HOME");
	static char *prev_dir, curr_dir[PATH_MAX];
	char *dir[2];

	if (args[1] == NULL)
	{
		dir[0] = home;
		getcwd(curr_dir, PATH_MAX);
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		if (prev_dir != NULL)
			dir[0] = prev_dir;
		else
		{
			write(2, "./hsh: cd: OLDPWD not set\n", 26);
			return (1);
		}
	}
	else
	{
		dir[0] = args[1];
		getcwd(curr_dir, PATH_MAX);
	}
	dir[1] = NULL;
	prev_dir = curr_dir;
	getcwd(curr_dir, PATH_MAX);
	if (chdir(dir[0]) != 0)
	{
		perror("cd");
		return (1);
	}
	else
	{
		getcwd(curr_dir, PATH_MAX);
		setenv("PWD", curr_dir, 1);
		return (0);
	}
	return (0);
}
