#include "shell.h"

/**
 * simple_help - Display helpful information about builtin commands
 * @args: The list of user input arguments
 * @env: The environmental variables
 *
 * Return: On successful execution 0, on failure a status value
 */
int simple_help(char **args, char **env)
{
	int i;
	char output[] = "These shell commands are defined internally.  Type \
`help' to see this list.\nType `help name' to find out more about the \
function `name'.\nalias\ncd\nenv\nexit\nhelp\nsetenv\nunsetenv\n";


/* cd exit alias help setenv unsetenv env */
	(void) env;
	if (args[1] == NULL)
		write(STDOUT_FILENO, output, _strlen(output));
	else
		which_help(args[1]);

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);

	return (EXIT_SUCCESS);
}

/**
 * simple_history - Display the history list
 * @args: The list of user input arguments
 * @env: The environmental variables
 *
 * Return: On successful execution 0, on failure a status value
 */
int simple_history(char **args, char **env)
{
	int i;

	(void) env;

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);

	args[0] = _strdup("echo");
	args[1] = _strdup("$HISTFILE");

	return (EXIT_SUCCESS);
}

/**
 * simple_env - prints the current enviroment variable values
 * @args:list of user input arguments
 *
 * Return: On successful execution 0, on failure a nonzero value
 */
int simple_env(char **args, char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
	return (EXIT_SUCCESS);
}

/**
 * simple_exit - cause a termination of simple shell
 * @args: list of user input arguments
 *
 * Return: On successful execution 0, on failure a status value
 */
int simple_exit(char **args, char **env)
{
	int i, status;
	(void) env;

	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
		if ((status < 0) || (status > 255))
			status = 2;
	}

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
	exit(status);
	return (EXIT_SUCCESS);
}

/**
 * not_built_in - handles the case if inputted command isn't a built-in
 * @args: list of user input arguments
 *
 * Return: Always returns EXIT_FAILURE
 */
int not_built_in(char **args, char **env)
{
	(void) args;
	(void) env;

	return (EXIT_FAILURE);
}
