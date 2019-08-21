#include "shell.h"

/**
 * strtow - Split a string into words
 * @str: The string to split
 * @delim: The character delimiters
 *
 * Return: Pointer to newly allocated space containing an array of words,
 * or NULL if failure
 */
char **strtow(char *str, char *delim)
{
	int i = 0, j = 0, k = 0, wordcount = 0, strlength = 0, tmplength = 0;
	char **words;

	if (str == NULL || _strlen(str) == 0)
		return (NULL);
	strlength = _strlen(str);
	wordcount = count_words(str, delim);
	if (wordcount == 0)
		return (NULL);
	words = malloc(sizeof(char *) * (wordcount + 1));
	if (words == NULL)
		return (NULL);
	for (i = 0; i < strlength; i++)
	{
		if (_strpbrk(delim, str[i]) == 0)
		{
			for (k = i, tmplength = 0; str[k] != '\0' &&
				     _strpbrk(delim, str[k]) == 0; k++)
				tmplength++;
			words[j] = malloc(sizeof(char) * (tmplength + 1));
			if (words[j] == NULL)
			{
				free(words);
				for (k = 0; k <= j; k++)
					free(words[k]);
				return (NULL);
			}
			k = 0;
			while (str[i] != '\0' && _strpbrk(delim, str[i]) == 0)
			{
				words[j][k] = str[i];
				i++;
				k++;
			}
			words[j][k] = '\0';
			j++;
		}
	}
	words[j] = NULL;
	return (words);
}

/**
 * count_words - Count the number of words in a string
 * @str: The string
 * @delim: The character delimiters
 *
 * Return: The number of words (any characters separated by spaces)
 */
int count_words(char *str, char *delim)
{
	int i;
	int count = 0, word = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (_strpbrk(delim, str[i]) == 0 && word == 0)
		{
			count++;
			word = 1;
		}
		else if (_strpbrk(delim, str[i]) == 1)
		{
			word = 0;
		}
	}

	return (count);
}

/**
 * _strlen - Return the length of a string
 * @s: The string to check
 *
 * Return: The length of the string
 */
int _strlen(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strstr - Locate a substring
 * @haystack: The string to search
 * @needle: The substring to search for
 *
 * Return: Pointer to the first occurrence of the substring needle
 * in the string haystack
 */
char *_strstr(char *haystack, const char *needle)
{
	int i, j, size_haystack, size_needle;
	char *p = '\0';

	if (needle[0] == '\0')
		return (haystack);

	size_haystack = _strlen(haystack);
	size_needle = _strlen(needle);

	for (i = 0; i < size_haystack; i++)
	{
		if (haystack[i] == needle[0])
		{
			p = &haystack[i];
			for (j = 0; j < size_needle; j++)
			{
				if (haystack[i + j] != needle[j])
				{
					p = '\0';
					break;
				}

				if (j == size_needle - 1)
					i = size_haystack;
			}
		}
	}

	return (p);
}

/**
 * _strchr - Locate a character in a string
 * @s: The string to search
 * @c: The character to search for
 *
 * Return: Pointer to the first occurrence of the character c
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return (&s[i]);

	if (s[i] == c)
		return (&s[i]);

	return ('\0');
}
