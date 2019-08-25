#include "shell.h"

/**
 * main - provides a prompt to be interpreted by the shell
 * @ac: number of items in av
 * @av: NULL terminated array of strings representing inputted arguments
 * @env: NULL terminated array of strings representing current enviroment
 *
 * Return: On success returns 0, on failure provides error number
 */
int main(int ac, char **av)
{
	size_t len = 0;
	ssize_t read = 0;
	char *line = NULL;
	char **args = NULL;
	list_t *env = set_env_list();
	(void) ac;
	(void) av;

	while (read != -1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		read = getline(&line, &len, stdin);
		if (read != -1)
		{
			remove_comments(line);
			if (only_delims(line))
				continue;
			args = strtow(line, " \t\r\n\v\f");
			replace_dollars(args, env);
			if (_strcmp(args[0], "exit") == 0)
			{
				free(line);
				free_list(env);
			}
			if (get_built_in(args[0])(args, env) == EXIT_SUCCESS)
				continue;
			search_path(args, env);
			execute(args);
		}
	}

	free(line);
	free_list(env);
	return (EXIT_SUCCESS);
}

/**
 * only_delims - Check if line consists of only delimiters
 * @line: The line to check
 *
 * Return: 1 if true, 0 if false
 */
int only_delims(char *line)
{
	int i, j, delim_found;
	char delim[] = " \t\r\n\v\f";

	for (i = 0; line[i] != '\0'; i++)
	{
		delim_found = 0;
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (line[i] == delim[j])
				delim_found = 1;
		}
		if (!delim_found)
			return (0);
	}

	return (1);
}
