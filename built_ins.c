#include "shell.h"

/**
 * simple_help - Display helpful information about builtin commands
 * @args: The list of user input arguments
 * @env: The environmental variables
 * @status: The status struct
 *
 * Return: On successful execution 0, on failure a status value
 */
int simple_help(char **args, list_t *env, status_t *status)
{
	char output[] = "These shell commands are defined internally.  Type ";
	char output2[] = "`help' to see this list.\nType `help name' to find ";
	char output3[] = "out more about the function `name'.\n";
	char output4[] = "alias\ncd\nenv\nexit\nhelp\nsetenv\nunsetenv\n";

	(void) env;
	(void) status;
	if (args[1] == NULL)
	{
		write(STDOUT_FILENO, output, _strlen(output));
		write(STDOUT_FILENO, output2, _strlen(output2));
		write(STDOUT_FILENO, output3, _strlen(output3));
		write(STDOUT_FILENO, output4, _strlen(output4));
	}
	else
		which_help(args[1]);

	free_args(args);
	return (0);
}

/**
 * simple_history - Display the history list
 * @args: The list of user input arguments
 * @env: The environmental variables
 * @status: The status struct
 *
 * Return: On successful execution 0, on failure a status value
 */
int simple_history(char **args, list_t *env, status_t *status)
{
	char output[] = "History may be implemented in a future release.\n";

	(void) env;
	(void) status;
	write(STDOUT_FILENO, output, _strlen(output));
	free_args(args);

	return (0);
}

/**
 * simple_cd - changes current directory
 * @args: list of user input arguments
 * @env: the enviromental variables
 * @status: The status struct
 *
 * Return: On successful execution 0, on failure a status value
 */
int simple_cd(char **args, list_t *env, status_t *status)
{
	int exec_stat, is_sign = 0;
	char *input_dir = args[1];
	char *current_dir;
	char *error_msg;
	char buff[4096]; /* PATH_MAX = 4096 */

	if (input_dir == NULL || _cmpstrandlen(input_dir, "~") == 0)
		exec_stat = chdir(_getenv_value("HOME", env));
	else if (_cmpstrandlen(input_dir, "-") == 0)
		exec_stat = chdir(_getenv_value("OLDPWD", env)), is_sign = 1;
	else
		exec_stat = chdir(input_dir);

	if (exec_stat != 0)
	{
		error_msg = str_concat("can't cd to ", input_dir);
		print_error(args, env, error_msg, status);
		free(error_msg);
		free_args(args);
		return (2);
	}

	_setenv("OLDPWD", _getenv_value("PWD", env), &env);
	_setenv("PWD", getcwd(buff, 4096), &env);

	current_dir = _getenv_value("PWD", env);
	if (is_sign)
	{
		write(STDERR_FILENO, current_dir, _strlen(current_dir));
		write(STDERR_FILENO, "\n", 1);
	}
	free_args(args);
	return (0);
}

/**
 * simple_exit - cause a termination of simple shell
 * @args: list of user input arguments
 * @env: the enviromental variables
 * @status: The status struct
 *
 * Return: On successful execution 0, on failure a status value
 */
int simple_exit(char **args, list_t *env, status_t *status)
{
	int last_status = status->last_status;

	free_args(args);
	free_list(env);
	free_status(status);
	exit(last_status);
	return (0);
}

/**
 * not_built_in - handles the case if inputted command isn't a built-in
 * @args: list of user input arguments
 * @env: the enviromental variables
 * @status: The status struct
 *
 * Return: Always returns -1
 */
int not_built_in(char **args, list_t *env, status_t *status)
{
	(void) args;
	(void) env;
	(void) status;

	return (-1);
}
