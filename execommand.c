#include "shell.h"


int execmd(char **args,char *av[],int i)
{
        pid_t pid;
        int stat;

	printf("%s\n", args[0]);
	if (strcmp(args[0], "exit") == 0)
	{	
		exit_status(args);
	}

        pid = fork();
        if (pid == 0)
        {
                execve(args[0],args,NULL);
		if (i == 1)
                	perror(*(av + 0));
		else
			/*change error here for non interactive*/
			perror(*(av + 0));
                return 1;
        }
        else if (pid > 0)
        {
                waitpid(pid, &stat,0);
        }
        else
        {
                printf("fork failed");
                exit(1);
        }
	return (0);
}
