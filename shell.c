#include "shell.h"

/**
 * main - provides a prompt to be interpreted by the shell
 * @ac: number of items in av
 * @av: NULL terminated array of strings representing inputted arguments
 * @env: NULL terminated array of strings representing current enviroment
 *
 * Return: On success returns 0, on failure provides error number
 */
int main(int ac, char **av, char **env)
{
	ssize_t read = 0;
	char *line = NULL;
	size_t len = 0;
	char **args;
	int i;

	(void) ac;
	(void) av;

	while (read != -1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		read = getline(&line, &len, stdin);
		for (i = 0; i < _strlen(line); i++)
			if (line[i] == '\n')
				line[i] = '\0';
		args = strtow(line, ' ');
		if (get_built_in(args[0])(args, env) == EXIT_SUCCESS)
			continue;
		search_path(args, env);
 		execute(args);
	}

	free(line);
	return (EXIT_SUCCESS);
}
