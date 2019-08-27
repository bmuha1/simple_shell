#include "shell.h"

void search_path_list(char **args, list_t *env)
{
	int i, j;
	char delim = ':';
	char *new_word;
	char *path = NULL;
	char *tmp = NULL;
	char *tmp2 = NULL;
	list_t *dir_list = NULL;
	list_t *h = NULL;
	struct stat st;

	path = _getenv_value("PATH", env);
	if (path == NULL)
		return;

	/* set directory list */
	i = 0;
        while (path[i] != '\0')
        {
                new_word = malloc(_strlen(path) * sizeof(char));
                j = 0;
                while (path[i] != delim && path[i] != '\0')
                {
                        new_word[j] = path[i];
                        i++;
                        j++;
                }
                if (path[i] != '\0')
                        i++;
                new_word[j] = '\0';
                if (!_strcmp(new_word, "\0") && _strlen(new_word) == _strlen("\0"))
                        add_node_end(&dir_list, ".");
                else
                        add_node_end(&dir_list, new_word);
                free(new_word);
        }
        if (path[i] == '\0' && path[i-1] == delim)
                add_node_end(&dir_list, ".");

	/* check if executable exists in any of the directories */
	h = dir_list;
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
	free_list(dir_list);
}
