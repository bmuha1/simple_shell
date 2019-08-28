#include "shell.h"

/**
 * init_status - Initialize the status struct
 * @status: The status struct
 * @last_status: The last status
 * @count: The count
 * @argv: The name of the program used to run the shell
 */
void init_status(struct status_s *status, int last_status, unsigned int count,
		 char *argv)
{
	if (status == NULL)
		return;
	status->last_status = last_status;
	status->count = count;
	status->argv = argv;
}

/**
 * new_status - Create a new status struct
 * @last_status: The last status
 * @count: The count
 * @argv: The name of the program used to run the shell
 *
 * Return: Pointer to the new status
 */
status_t *new_status(int last_status, unsigned int count, char *argv)
{
	status_t *new;
	int i, argv_len;

	argv_len = _strlen(argv);

	new = malloc(sizeof(status_t));
	if (new == NULL)
		return (NULL);

	new->argv = malloc(sizeof(char) * (argv_len + 1));
	if (new->argv == NULL)
	{
		free(new);
		return (NULL);
	}

	for (i = 0; i <= argv_len; i++)
		new->argv[i] = argv[i];
	new->last_status = last_status;
	new->count = count;

	return (new);
}

/**
 * free_status - Free a status
 * @status: The status to free
 */
void free_status(status_t *status)
{
	if (status == NULL)
		return;

	free(status->argv);
	free(status);
}
