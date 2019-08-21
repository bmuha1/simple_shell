#include "shell.h"

/**
 * _strcmp - compares two strings
 *
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: 0 if same, neg if s1 < s2, pos if s1 > s2
 *
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; s1[i] != '\0'; i++)
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * get_built_in - finds corresponding built-in executable
 * @cmd: potential built-in command input by user
 *
 * Return: Built-in function to execute
 */
int (*get_built_in(char *cmd))(char **args)
{
	int i;
	cmd_t command[] = {
		{"exit", simple_exit},
		{"env", simple_env},
		{NULL, not_built_in}
	};

	for (i = 0; command[i].type != NULL; i++)
	{
		if (!_strcmp(cmd, command[i].type))
			return (command[i].exec_built_in);
	}
	return (command[i].exec_built_in);
}
