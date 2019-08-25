#include "shell.h"

/**
 * execute - creates a new process to execute a command
 * @args: NULL terminated array of argument strings
 * @env: The environmental variables
 *
 * Return: On success of execution 0, 1 on failure
 */
int execute(char **args, list_t *env)
{
	pid_t child;
	int i, status = 0;

	child = fork();
	if (child == -1)
		return (98);
	else if (child == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			write(STDERR_FILENO, _getenv_value("argv", env),
			      _strlen(_getenv_value("argv", env)));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, _getenv_value("count", env),
			      _strlen(_getenv_value("count", env)));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, args[0], _strlen(args[0]));
			write(STDERR_FILENO, ": not found\n", 12);
			return (127);
		}
	}
	else
		wait(&status);

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);

	return (EXIT_SUCCESS);
}
