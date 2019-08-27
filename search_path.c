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
	list_t *head = set_dir_list(env);
	list_t *h = head;
	struct stat st;

	for (i = 0; h != NULL; ++i, h = h->next)
	{
		tmp = str_concat(h->var, "/");
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
	free_list(head);
}

/**
 * set_dir_list - Create a linked list of directories from the path env var
 * @env: The enviromental variables
 *
 * Return: The list of directories
 */
list_t *set_dir_list(list_t *env)
{
	int i, j;
	char *new_word;
	char delim = ':';
	char *path = NULL;
	list_t *dir_list = NULL;

	path = _getenv_value("PATH", env);
	if (path == NULL)
		return (NULL);

	i = 0;
	if (path[0] == '\0')
	{
		add_node_end(&dir_list, ".");
		return (dir_list);
	}
	while (path[i] != '\0')
	{
		new_word = malloc(_strlen(path) * sizeof(char));
		if (new_word == NULL)
		{
			free(new_word);
			return (NULL);
		}
		for (j = 0; path[i] != delim && path[i] != '\0'; i++, j++)
			new_word[j] = path[i];
		if (path[i] != '\0')
			i++;
		new_word[j] = '\0';
		if (_cmpstrandlen(new_word, "\0") == 0)
			add_node_end(&dir_list, ".");
		else
			add_node_end(&dir_list, new_word);
		free(new_word);
	}
	if (path[i] == '\0' && path[i - 1] == delim)
		add_node_end(&dir_list, ".");
	return (dir_list);
}
