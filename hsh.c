#include "shell.h"

int main(int ac, char *av[])
{
	char *input = NULL;
	size_t n;
	ssize_t read;
	char **args;
	int interactive = isatty(STDIN_FILENO);

	if (interactive)
	{
	while (1)
	{
		write(1,"myShell$ ",9);
		read = getline(&input, &n, stdin);
		if(read == -1)
		{
			write(1,"\n",1);
			exit(0);
		}
		if (strcmp(input,"\n") == 0)
			continue;
		/*execute the commande */
		/*to handle the arguments we need to strlok the input: */
		args = arg_sep(input);
		execmd(args, av, 1);
 	}
	}
	else
	{
		while (getline(&input, &n, stdin) > 0)
		{
			//input[strcspn(input, "\n")] = '\0';
			args = arg_sep(input);
			execmd(args, av, 0);
		}

	}
	return 0;
}
