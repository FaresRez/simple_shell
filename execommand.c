#include "shell.h"

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
		if (!i)
			printf("%s: 1: %s: not found\n", av[0], args[0]);
		else
			printf("%s: Command not found\n", input);
		return;
	}

		
	pid = fork();
        if (pid == 0)
        {
                execve(full_cmd, args, environ);
		if (i == 1)
		{
			write(2,"-hsh: ", 6);
			perror(args[0]);
		}
		else
		{
			printf("%s: 1: %s: not found\n", av[0], args[0]);
		}
                return;
        }
        else if (pid > 0)
        {
		//check if the command already has absolute path or not
		//if it doesn't it means path was added and full_cmd needs to be freed
		if (strlen(full_cmd) != strlen(args[0]))
			free(full_cmd);
                waitpid(pid, &stat,0);
        }
        else
        {
                printf("fork failed");
        }
}
