#include "shell.h"

/**
 * simple_help - Display helpful information about builtin commands
 * @args: The list of user input arguments
 * @env: The environmental variables
 *
 * Return: On successful execution 0, on failure a status value
 */
int simple_help(char **args, list_t *env)
{
	int i;
	char output[] = "These shell commands are defined internally.  Type ";
	char output2[] = "`help' to see this list.\nType `help name' to find ";
	char output3[] = "out more about the function `name'.\n";
	char output4[] = "alias\ncd\nenv\nexit\nhelp\nsetenv\nunsetenv\n";

	(void) env;
	if (args[1] == NULL)
	{
		write(STDOUT_FILENO, output, _strlen(output));
		write(STDOUT_FILENO, output2, _strlen(output2));
		write(STDOUT_FILENO, output3, _strlen(output3));
		write(STDOUT_FILENO, output4, _strlen(output4));
	}
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
int simple_history(char **args, list_t *env)
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
 * simple_cd - changes current directory
 * @args: list of user input arguments
 * @env: the enviromental variables
 *
 * Return: On successful execution 0, on failure a status value
 */
int simple_cd(char **args, list_t *env)
{
	int exec_stat, i;
	char *input_dir = args[1];
	char buff[4096]; /* PATH_MAX = 4096 */

	if (input_dir == NULL)
		exec_stat = chdir(_getenv_value("HOME", env));
	else if (!_strcmp(input_dir, "-"))
		exec_stat = chdir(_getenv_value("OLDPWD", env));
	else
		exec_stat = chdir(input_dir);

	if (exec_stat != 0)
		return (exec_stat);

	_setenv("OLDPWD", _getenv_value("PWD", env), &env);
	_setenv("PWD", getcwd(buff, 4096), &env);
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
	return (exec_stat);
}

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


/**
 * simple_exit - cause a termination of simple shell
 * @args: list of user input arguments
 * @env: the enviromental variables
 *
 * Return: On successful execution 0, on failure a status value
 */
int simple_exit(char **args, list_t *env)
{
	int i, status;
	(void) env;

	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
		if ((status < 0) || (status > 255))
			return (EXIT_SUCCESS);
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
 * @env: the enviromental variables
 *
 * Return: Always returns EXIT_FAILURE
 */
int not_built_in(char **args, list_t *env)
{
	(void) args;
	(void) env;

	return (EXIT_FAILURE);
}
