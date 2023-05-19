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
			perror("execve");
		}
                return;
        }
        else if (pid > 0)
        {
		//check if the command already has absolute path or not
		//if it doesn't it means full_cmd needs to be freed
		if (strlen(full_cmd) != strlen(args[0]))
			free(full_cmd);
                waitpid(pid, &stat,0);
        }
        else
        {
                printf("fork failed");
        }
}
