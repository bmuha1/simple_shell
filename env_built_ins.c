#include "shell.h"

/**
 * simple_env - prints the current enviroment variable values
 * @args: list of user input arguments
 * @env: the enviromental variables
 * @status: The status struct
 *
 * Return: On successful execution 0, on failure a nonzero value
 */
int simple_env(char **args, list_t *env, status_t *status)
{
	int i;

	(void) status;
	for (i = 0; env != NULL; i++)
	{
		write(STDOUT_FILENO, env->var, _strlen(env->var));
		write(STDOUT_FILENO, "\n", 1);
		env = env->next;
	}

	free_args(args);
	return (0);
}

/**
 * simple_unsetenv - remove an enviorment variable
 * @args: list of user input arguments
 * @env: the enviromental variables
 * @status: The status struct
 *
 * Return: On successful execution 0, on failure 2
 */
int simple_unsetenv(char **args, list_t *env, status_t *status)
{
	if (args[1] == NULL)
	{
		print_error(args, env, "Please provide an argument", status);
		free_args(args);
		return (2);
	}
	_unsetenv(args[1], &env);
	free_args(args);
	return (0);
}

/**
 * simple_setenv - initialize a new or modify an existing enviromental variable
 * @args: list of user input arguments
 * @env: the enviromental variables
 * @status: The status struct
 *
 * Return: On successful execution 0, on failure 2
 */
int simple_setenv(char **args, list_t *env, status_t *status)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		print_error(args, env, "Please provide arguments", status);
		free_args(args);
		return (2);
	}
	_setenv(args[1], args[2], &env);
	free_args(args);
	return (2);
}
