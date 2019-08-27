#include "shell.h"

/**
 * _atoi - convert string to integer (taking account of signs in string)
 *
 * @s: string to convert
 *
 * Return: converted integer value
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = -1;
	int i = 0;

	for (; s[i] != '\0' && (s[i] < '0' || s[i] > '9'); i++)
	{
		if (s[i] == '-')
			sign *= -1;
	}
	for (; s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'); i++)
		result = (result * 10) - (s[i] - '0');
	result *= sign;
	return (result);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: 0 if same, neg if s1 < s2, pos if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; s1[i] != '\0'; i++)
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _cmpstrandlen - compares two strings and compares the length of the strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: If strings are the "same" return 0 else 1
 */
int _cmpstrandlen(char *s1, char *s2)
{
	if (!_strcmp(s1, s2) && (_strlen(s1) == _strlen(s2)))
		return (0);
	else
		return (1);
}

/**
 * _ntoa - convert an int to a string
 * @n: int to convert
 * @s: the string
 */
void _ntoa(int n, char *s)
{
	_ntoa_rev(n, s);
	rev_string(s);
}
