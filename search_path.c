#include "shell.h"

/**
 * search_path - Check if the program exists in any path directories
 * @args: The command line arguments
 * @env: The environmental variables
 */
void search_path(char **args, list_t *env)
{
	int i;
	char *tmp = NULL;
	char *tmp2 = NULL;
	char **path = NULL;
	char **path2 = NULL;
	struct stat st;

	tmp = _getenv("PATH", env);
	path = strtow(tmp, "=");
	path2 = strtow(path[1], ":");

	if (!path2)
		return;

	for (i = 0; path2[i] != NULL; i++)
	{
		tmp = str_concat(path2[i], "/");
		tmp2 = str_concat(tmp, args[0]);
		free(tmp);

		if (stat(tmp2, &st) == 0)
		{
			free(args[0]);
			args[0] = _strdup(tmp2);
			free(tmp2);
			break;
		}
		else
			free(tmp2);
	}

	for (i = 0; path[i] != NULL; i++)
		free(path[i]);
	free(path);

	for (i = 0; path2[i] != NULL; i++)
		free(path2[i]);
	free(path2);
}
