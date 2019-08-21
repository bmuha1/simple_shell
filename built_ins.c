#include "shell.h"

/**
 * _atoi - convert string to integer (taking account of signs in string)
 *
 * @s: string to convert
 * Return: converted integer value
 *
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = -1;
	int i = 0;

	for (; s[i] != '\0' && (s[i] < '0' || s[i] > '9'); i++)
	{
		if (s[i] == '-')
			sign *= -1;
	}
	for (; s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'); i++)
		result = (result * 10) - (s[i] - '0');
	result *= sign;
	return (result);
}

/**
 * simple_exit - cause a termination of simple shell
 * @args: list of user input arguments
 *
 * Return: On successful execution 0, on failure a status value
 */
int simple_exit(char **args)
{
	int i, status;

	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
		if ((status < 0) || (status > 255))
			status = 2;
	}
	exit(status);

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
	return (EXIT_SUCCESS);
}

/**
 * not_built_in - handles the case if inputted command isn't a built-in
 * @args: list of user input arguments
 *
 * Return: Always returns EXIT_FAILURE
 */
int not_built_in(char **args)
{
	(void) args;

	return (EXIT_FAILURE);
}
