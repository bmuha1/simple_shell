#include "shell.h"

/**
 * simple_env - prints the current enviroment variable values
 * @args: list of user input arguments
 * @env: the enviromental variables
 *
 * Return: On successful execution 0, on failure a nonzero value
 */
int simple_env(char **args, list_t *env)
{
	int i;

	for (i = 0; env != NULL; i++)
	{
		write(STDOUT_FILENO, env->var, _strlen(env->var));
		write(STDOUT_FILENO, "\n", 1);
		env = env->next;
	}
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
	return (EXIT_SUCCESS);
}

/**
 * simple_unsetenv - remove an enviorment variable
 * @args: list of user input arguments
 * @env: the enviromental variables
 *
 * Return: On successful execution 0, on failure a nonzero value
 */
int simple_unsetenv(char **args, list_t *env)
{
	int i;

	if (args[1] == NULL)
	{
		perror("Please provide an argument");
		return (EXIT_FAILURE);
	}
	_unsetenv(args[1], &env);
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
	return (EXIT_SUCCESS);
}

/**
 * simple_setenv - initialize a new or modify an existing enviromental variable
 * @args: list of user input arguments
 * @env: the enviromental variables
 *
 * Return: On successful execution 0, on failure a nonzero value
 */
int simple_setenv(char **args, list_t *env)
{
	int i;

	if (args[1] == NULL || args[2] == NULL)
	{
		perror("Please provide arguments");
		return (EXIT_FAILURE);
	}
	_setenv(args[1], args[2], &env);
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
	return (EXIT_SUCCESS);
}
