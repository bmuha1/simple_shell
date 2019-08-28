#include "shell.h"

/**
 * replace_dollars - Replace $$, $?, and $ variable replacement
 * @args: The arguments
 * @env: The environment variables
 * @status: The status struct
 */
void replace_dollars(char **args, list_t *env, status_t *status)
{
	int i, pid;
	char pid_string[12] = "", tmp2[12] = "";
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
				/* tmp = _getenv_value("last_status", env); */
				_ntoa(status->last_status, tmp2);
				if (tmp2[0] == '\0')
					tmp2[0] = '0';
				args[i] = _strdup(tmp2);
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
