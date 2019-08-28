#include "shell.h"

/**
 * main - provides a prompt to be interpreted by the shell
 * @ac: number of items in av
 * @av: NULL terminated array of strings representing inputted arguments
 *
 * Return: On success returns 0, on failure provides error number
 */
int main(__attribute__((__unused__)) int ac, char **av)
{
	size_t len = 0;
	ssize_t read = 0;
	char *line = NULL;
	char **args = NULL;
	list_t *env = set_env_list();
	int last_status;
	status_t *status;

	status = new_status(0, 0, av[0]);
	signal(SIGINT, handle_sigint);
	while (read != EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "<^^^> ", 6);
		read = getline(&line, &len, stdin);
		if (read != EOF)
		{
			status->count++;
			remove_comments(line);
			if (only_delims(line))
				continue;
			args = strtow(line, " \t\r\n\v\f");
			replace_dollars(args, env, status);
			if (_cmpstrandlen(args[0], "exit") == 0)
				free(line);
			status->last_status =
				get_built_in(args[0])(args, env, status);
			if (status->last_status == 0 ||
			    status->last_status == 2)
				continue;
			if (!_strpbrk(args[0], '/'))
				search_path(args, env);
			status->last_status = execute(args, env, status);
		}
	}
	last_status = status->last_status;
	free(line), free_list(env), free_status(status);
	return (last_status);
}

/**
 * handle_sigint - Handle the signal Ctrl+C
 * @sig: The signal
 */
void handle_sigint(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "\n<^^^> ", 7);
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
