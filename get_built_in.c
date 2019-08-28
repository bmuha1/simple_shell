#include "shell.h"

/**
 * get_built_in - finds corresponding built-in executable
 * @cmd: potential built-in command input by user
 *
 * Return: Built-in function to execute
 */
int (*get_built_in(char *cmd))(char **args, list_t *env, status_t *status)
{
	int i;
	cmd_t command[] = {
		{"exit", simple_exit},
		{"env", simple_env},
		{"unsetenv", simple_unsetenv},
		{"setenv", simple_setenv},
		{"help", simple_help},
		{"history", simple_history},
		{"cd", simple_cd},
		{NULL, not_built_in}
	};

	for (i = 0; command[i].type != NULL; i++)
	{
		if (_cmpstrandlen(cmd, command[i].type) == 0)
			return (command[i].exec_built_in);
	}
	return (command[i].exec_built_in);
}
