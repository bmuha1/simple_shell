#include "shell.h"

/**
 * execute - creates a new process to execute a command
 * @args: NULL terminated array of argument strings
 *
 * Return: On success of execution 0, 1 on failure
 */
int execute(char **args)
{
	pid_t child;
	int i, status = 0;

	child = fork();
	if (child == -1)
		exit(98);
	else if (child == 0)
	{
		     if(execve(args[0], args, NULL) == -1)
		     {
			     perror("Can not execute");
			     exit(EXIT_FAILURE);
		     }
	}
	else
		wait(&status);

        for (i = 0; args[i] != NULL; i++)
                free(args[i]);
	free(args);

	return (EXIT_SUCCESS);
}
