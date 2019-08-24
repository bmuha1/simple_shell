#include "shell.h"

/**
 * replace_dollars - Replace $$, $?, and $ variable replacement
 * @args: The arguments
 * @env: The environment variables
 */
void replace_dollars(char **args, list_t *env)
{
	int i, pid;
	char pid_string[12];
	char *tmp = NULL, *env_var = NULL, *equal_location = NULL;

	for (i = 0; i < 12; i++)
		pid_string[i] = '\0';
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
			else
			{
				env_var = &args[i][1];
				tmp = _getenv(env_var, env);
				if (tmp)
				{
					equal_location = _strchr(tmp, '=');
					free(args[i]);
					args[i] = _strdup(equal_location + 1);
				}
				else
				{
					free(args[i]);
					args[i] = _strdup("");
				}
			}
		}
	}
}
