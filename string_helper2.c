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

/**
 * _strpbrk - Search a string for a character
 * @s: The string to search
 * @accept: The character to search for
 *
 * Return: 1 if found, 0 otherwise
 */
int _strpbrk(char *s, char accept)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == accept)
			return (1);
	}

	return (0);
}

/**
 * rev_string - Reverse a string
 * @s: The string to reverse
 */
void rev_string(char *s)
{
	int i, length;
	char tmp;

	length = 0;
	for (i = 0; s[i] != '\0'; i++)
		length++;

	for (i = 0; i < length; i++)
	{
		tmp = s[i];
		s[i] = s[length - 1];
		s[length - 1] = tmp;
		length--;
	}
}

/**
 * _ntoa_rev - Convert an int to a reversed string
 * @n: The int to convert
 * @s: The reversed string
 */
void _ntoa_rev(int n, char *s)
{
	if (n == 0)
	{
		*s = '\0';
		return;
	}

	*s = (n % 10) + '0';
	_ntoa_rev(n / 10, ++s);
}
