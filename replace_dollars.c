#include "shell.h"

/**
 * replace_dollars - Replace $$, $?, and $ variable replacement
 * @args: The arguments
 * @env: The environment variables
 */
void replace_dollars(char **args, list_t *env)
{
	int i, pid;
	char pid_string[12] = "";
	char *tmp = NULL;

	for (i = 0; i < 12; i++)
		pid_string[i] = '\0';
	for (i = 0; args[i] != NULL; i++)
	{
		if (args[i][0] == '$' && args[i][1] != '\0')
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
				free(args[i]);
				tmp = _getenv_value("old_status", env);
				args[i] = _strdup(tmp);
			}
			else
			{
				tmp = _strdup(&args[i][1]);
				free(args[i]);
				args[i] = _strdup(_getenv_value(tmp, env));
				free(tmp);
			}
		}
	}
}
