#include "shell.h"

extern char **environ;

list_t *add_node_end(list_t **head, char *var)
{
        list_t *new;
        list_t *temp = *head;

        new = malloc(sizeof(list_t));
        if (new == NULL)
                return (NULL);
        new->var = _strdup(var);
	new->next = NULL;

        if (*head == NULL)
                *head = new;
        else
        {
                while (temp->next != NULL)
                        temp = temp->next;
                temp->next = new;
        }
        return (new);
}

list_t *add_node_at_index(list_t **head, int idx, char *var)
{
	list_t *new;

	if (head == NULL)
		return (NULL);
	if (idx != 0)
	{
		if (*head != NULL)
			return (add_node_at_index(&(*head)->next,
							idx - 1, var));
		else
			return (NULL);
	}
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->var = _strdup(var);
	new->next = *head;
	*head = new;
	return (new);
}

list_t *set_env_list(void)
{
	list_t *envlist = NULL;

	while (*environ)
		add_node_end(&envlist, *environ++);
	return (envlist);
}

size_t print_list(const list_t *h)
{
        int len = 0;

        for (len = 0; h != NULL; ++len)
        {
                printf("%s\n", h->var);
                h = h->next;
        }
        return (len);
}

void free_list(list_t *h)
{
        if (h == NULL)
                return;
        free_list(h->next);
        free(h->var);
        free(h);
}

int delete_node_at_index(list_t **head, size_t index)
{
	list_t *tmp;

	if (head == NULL)
		return (-1);
	if (index != 0)
	{
		if (*head != NULL)
			return (delete_node_at_index(&(*head)->next,
							index - 1));
		else
			return (-1);
	}
	if (*head == NULL)
		return (-1);
	tmp = (*head)->next;
	free((*head)->var);
	free(*head);
	*head = tmp;
	return (1);
}

int find_var_index(char *name, list_t *h)
{
	int i, flag = 0;

	for (i = 0; h != NULL; i++, h = h->next)
	{
		if ((_strstr(h->var, name) == h->var) &&
		    *(h->var + _strlen(name)) == '=')
		{
			flag = 1;
			break;
		}
	}
	if (flag)
		return (i);
	else
		return (-1);
}

char *_getenv(char *name, list_t *h)
{
	while (h != NULL)
	{
		if ((_strstr(h->var, name) == h->var) &&
		   *(h->var + _strlen(name)) == '=')
			return (h->var);
		h = h->next;
	}
	perror("Enviroment variable wasn't found");
	return ("");
}

char *_getenv_value(char *name, list_t *h)
{
	char *var = NULL;
	char *value = NULL;

	var = _getenv(name, h);
	value = _strchr(var, '=');
	if (value == NULL || (value + 1) == NULL)
		return ("");
	return (value + 1);
}

void _unsetenv(char *name, list_t **head)
{
	int index = find_var_index(name, *head);
	int del_stat;

	if (index != -1)
		del_stat = delete_node_at_index(head, index);
	if (del_stat == -1)
		perror("Unable to unset");
}

void _setenv(char *name, char *value, list_t **head)
{
	int index = find_var_index(name, *head);
	char *new1;
	char *new2;
	char *new3;
	char *new4;

	new1 = _strdup(name);
	new2 = str_concat(new1, "=");
	free(new1);
	new3 = str_concat(new2, value);
	free(new2);
	new4 = str_concat(new3, "\0");
	free(new3);

	if (index != -1)
	{
		delete_node_at_index(head, index);
		add_node_at_index(head, index, new4);
	}
	else
		add_node_end(head, new4);

	free(new4);
}

/*int main(void)
{
	list_t *envlist = set_env_list();
	char *bob = "BANANANANANANA";

	print_list(envlist);
	printf("--------------------------------------------------------------------------------------\n");
	//_unsetenv("PATH", &envlist);
	//print_list(envlist);
	//_setenv("PATH", "DEATH", &envlist);
	//print_list(envlist);
	printf("%s\n", _getenv_value("HAHA", envlist));
	free_list(envlist);
	} */
