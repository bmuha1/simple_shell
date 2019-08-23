#include "shell.h"

/**
 * get_built_in - finds corresponding built-in executable
 * @cmd: potential built-in command input by user
 *
 * Return: Built-in function to execute
 */
int (*get_built_in(char *cmd))(char **args, char **env)
{
	int i;
	cmd_t command[] = {
		{"exit", simple_exit},
		{"env", simple_env},
		{"cd", simple_cd},
		{NULL, not_built_in}
	};

	for (i = 0; command[i].type != NULL; i++)
	{
		if (!_strcmp(cmd, command[i].type))
			return (command[i].exec_built_in);
	}
	return (command[i].exec_built_in);
}
