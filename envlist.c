#include "shell.h"

/**
 * set_env_list - sets an enviromental list
 *
 * Return: enviromental list
 */
list_t *set_env_list(void)
{
	list_t *envlist = NULL;

	while (*environ)
		add_node_end(&envlist, *environ++);
	return (envlist);
}

/**
 * _getenv - gets the var string relative to its name
 * @name: name from variable
 * @h: list to search from
 *
 * Return: String of variable else failure returns empty string
 */
char *_getenv(char *name, list_t *h)
{
	while (h != NULL)
	{
		if ((_strstr(h->var, name) == h->var) &&
		    *(h->var + _strlen(name)) == '=')
			return (h->var);
		h = h->next;
	}
	return ("");
}

/**
 * _getenv_value - gets the value relative to the name of var string
 * @name: name from variable
 * @h: list to search from
 *
 * Return: Value of variable string else failure returns empty string
 */
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

/**
 * _unsetenv - if env node found, removes it from the env list
 * @name: name from variable string
 * @head: reference to a list
 */
void _unsetenv(char *name, list_t **head)
{
	int index = find_var_index(name, *head);
	int del_stat;

	if (index != -1)
		del_stat = delete_node_at_index(head, index);
	if (del_stat == -1)
		perror("Unable to unset");
}

/**
 * _setenv - either modifies an existing env node or adds a node to the end
 * @name: name from variable string
 * @value: value from variable string
 * @head: reference to a list
 */
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
