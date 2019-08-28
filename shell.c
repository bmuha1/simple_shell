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
	int count = 0, last_status = 0;
	char count_string[12] = "", status_string[12] = "";
	char *line = NULL;
	char **args = NULL;
	list_t *env = set_env_list();

	_setenv("argv", av[0], &env), signal(SIGINT, handle_sigint);
	while (read != -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "<^^^> ", 6);
		read = getline(&line, &len, stdin);
		if (read != -1)
		{
			_ntoa(++count, count_string);
			_setenv("count", count_string, &env);
			remove_comments(line);
			if (only_delims(line))
				continue;
			args = strtow(line, " \t\r\n\v\f");
			replace_dollars(args, env);
			if (_cmpstrandlen(args[0], "exit") == 0)
			{free_args(args), free_list(env), free(line);
				exit(last_status); }
			last_status = get_built_in(args[0])(args, env);
			_ntoa(last_status, status_string);
			_setenv("last_status", status_string, &env);
			if (last_status == 0 || last_status == 2)
				continue;
			if (!_strpbrk(args[0], '/'))
				search_path(args, env);
			last_status = execute(args, env);
			_ntoa(last_status, status_string);
			_setenv("last_status", status_string, &env);
		}
	}
	free(line), free_list(env);
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
