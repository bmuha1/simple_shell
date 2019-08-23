#include "shell.h"

/**
 * replace_dollars - Replace $$, $?, and $ variable replacement
 * @args: The arguments
 * @env: The environment
 */
void replace_dollars(char **args, char **env)
{
	int i, j, pid;
	char pid_string[12];
	char *tmp = NULL;
	char *env_var = NULL;
	char *equal_location = NULL;

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
				env_var = &args[i][1];
				tmp = _getenv(env_var, env);
				equal_location = _strchr(tmp, '=');
				free(args[i]);
				args[i] = _strdup(equal_location + 1);
			}
		}
	}
}
