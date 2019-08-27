#include "shell.h"

/**
 * print_error - Print error message
 * @args: NULL terminated array of argument strings
 * @env: The environmental variables
 * @message: The error message
 */
void print_error(char **args, list_t *env, char *message)
{
	write(STDERR_FILENO, _getenv_value("argv", env),
	      _strlen(_getenv_value("argv", env)));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, _getenv_value("count", env),
	      _strlen(_getenv_value("count", env)));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, args[0], _strlen(args[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, "\n", 1);
}

