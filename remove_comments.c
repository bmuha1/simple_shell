#include "shell.h"

/**
 * remove_comments - Remove comments from the line of user input
 * @line: The user input
 */
void remove_comments(char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '#')
		{
			line[i] = '\0';
			break;
		}
	}
}

/**
 * replace_dollars - Replace $$, $?, and $ variable replacement
 * @args: The arguments
 * @env: The environment
 */
void replace_dollars(char **args, char **env)
{
	int i, j, pid;
	char pid_string[12];

	for (i = 0; i < 12; i++)
		pid_string[i] = '\0';

	(void) env;

	for (i = 0; args[i] != NULL; i++)
	{
		if (args[i][0] == '$')
		{
			if (args[i][1] == '$')
			{
				free(args[i]);
				pid = getpid();
				_ntoa_rev(pid, pid_string);
				rev_string(pid_string);
				args[i] = _strdup(pid_string);
			}
			else if (args[i][1] == '?')
			{
				/* handle $? */
				for (j = 0; env[j] != NULL; j++)
					printf("env[%d]: %s\n", j, env[j]);
			}
			else
			{
				/* handle variable replacement */
			}
		}
	}
}
