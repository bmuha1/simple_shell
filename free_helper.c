#include "shell.h"

/**
 * free_args - frees the string list of arguments
 * @args: arguments
 */
void free_args(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
}

/**
 * free_list - frees a given list
 * @h: list to free
 */
void free_list(list_t *h)
{
	if (h == NULL)
		return;
	free_list(h->next);
	free(h->var);
	free(h);
}
