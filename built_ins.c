#include "shell.h"

/**
 *
 *
 *
 */
int simple_cd(char **args, char **env)
{
	int exec_stat, i;
	char *input_dir = args[1];
	char buff[4096]; /* PATH_MAX = 4096 */

	if (input_dir == NULL)
		exec_stat = chdir(getenv("HOME"));
	else if (!_strcmp(input_dir, "-"))
		exec_stat = chdir(getenv("OLDPWD"));
	else
		exec_stat = chdir(input_dir);

	if (exec_stat != 0)
		return (exec_stat);
	else
	{
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", getcwd(buff, 4096), 1);
	}
	for (i = 0; args[i] != NULL; i++)
                free(args[i]);
        free(args);
	return (exec_stat);
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
			return (0);
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
