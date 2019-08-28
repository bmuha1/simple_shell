#include "shell.h"

/**
 * print_error - Print error message
 * @args: NULL terminated array of argument strings
 * @env: The environmental variables
 * @message: The error message
 * @status: The status struct
 */
void print_error(char **args, list_t *env, char *message, status_t *status)
{
	char count[12] = "";

	(void) env;
	_ntoa(status->count, count);
	write(STDERR_FILENO, status->argv, _strlen(status->argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, count, _strlen(count));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, args[0], _strlen(args[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, "\n", 1);
}
