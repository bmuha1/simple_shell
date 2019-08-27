#include "shell.h"

/**
 * add_node_end - add a node to the end of the list
 * @head: head node of the list
 * @var: variable string to add to new node
 *
 * Return: New node added
 */
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

/**
 * add_node_at_index - add a node at desired index
 * @head: reference to a list
 * @idx: index to place new node
 * @var: variable stringto add to new node
 *
 * Return: New node added
 */
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

/**
 * delete_node_at_index - delete a node at desired index
 * @head: reference to a list
 * @index: index to delete desired node
 *
 * Return: On success 1, on failure -1
 */
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

/**
 * find_var_index - find a node with given variable name
 * @name: name of variable located in a var string
 * @h: list to search through
 *
 * Return: On success returns index, on failure -1
 */
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
