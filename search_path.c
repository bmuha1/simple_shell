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
	char buff[4096]; /* PATH_MAX = 4096 */
	struct stat st;

	getcwd(buff, 4096);
	printf("buff: %s\n", buff);

	tmp = _getenv("PATH", env);
	if (tmp[0] == ':')
		tmp = str_concat(buff, tmp);
	else if (tmp[_strlen(tmp)] == ':')
		tmp = str_concat(tmp, buff);
	path = strtow(tmp, "=");
	path2 = strtow(path[1], ":");

	if (!path2)
		return;

	/* TESTING */
	for (i = 0; path2[i] != NULL; i++)
		printf("path[%d]: %s\n", i, path2[i]);

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
