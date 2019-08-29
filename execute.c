#include "shell.h"

/**
 * execute - creates a new process to execute a command
 * @args: NULL terminated array of argument strings
 * @env: The environmental variables
 * @status: The status struct
 *
 * Return: On success of execution 0, 1 on failure
 */
int execute(char **args, list_t *env, status_t *status)
{
	pid_t child;
	int status2 = 0, exit_status = 0;

	child = fork();
	if (child == -1)
	{
		return (1);
	}
	else if (child == 0)
	{
		if (!_strpbrk(args[0], '/'))
		{
			print_error(args, env, "not found", status);
			exit(127);
		}
		if (execve(args[0], args, NULL) == -1)
		{
			print_error(args, env, "not found", status);
			exit(127);
		}
	}
	else
		waitpid(child, &status2, 0);

	if (WIFEXITED(status2))
		exit_status = WEXITSTATUS(status2);

	free_args(args);
	return (exit_status);
}
