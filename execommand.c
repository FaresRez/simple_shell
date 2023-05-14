#include "shell.h"


int execmd(char *cmd,char *av[],int i)
{
        pid_t pid;
        char *arr[] = {cmd,NULL};
        int stat;

        pid = fork();
        if (pid == 0)
        {
                execve(cmd,arr,NULL);
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
}
