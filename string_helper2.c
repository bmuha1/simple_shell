#include "shell.h"

/**
 * str_concat - Concatenate two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: Pointer to newly allocated space containing both strings,
 * or NULL if failure
 */
char *str_concat(char *s1, char *s2)
{
	int i, size1, size2;
	char *cat;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	size1 = _strlen(s1);
	size2 = _strlen(s2);

	cat = malloc(sizeof(char) * (size1 + size2 + 1));
	if (cat == NULL)
		return (NULL);

	for (i = 0; i < size1; i++)
		cat[i] = s1[i];
	for (; i < size1 + size2; i++)
		cat[i] = s2[i - size1];
	cat[size1 + size2] = '\0';

	return (cat);
}

/**
 * _strdup - Duplicate a string
 * @str: The string to duplicate
 *
 * Return: Pointer to the duplicate, or NULL if it fails
 */
char *_strdup(char *str)
{
	int i, length;
	char *dup;

	if (str == NULL)
		return (NULL);

	length = _strlen(str);
	dup = malloc(sizeof(char) * length + 1);
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		dup[i] = str[i];
	dup[length] = str[length];

	return (dup);
}
