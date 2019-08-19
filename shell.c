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
	char delim = ' ';

	(void) ac;
	(void) av;
	(void) env;

	while (read != -1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		if((read = getline(&line, &len, stdin)) != -1)
		{
			for (i = 0; i < _strlen(line); i++)
				if (line[i] == '\n')
					line[i] = '\0';
			args = strtow(line, delim);
			execute(args); /*handle exit cases in here ? */
		}
	}
	return (EXIT_SUCCESS);
}
