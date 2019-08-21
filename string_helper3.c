#include "shell.h"

/**
 * _atoi - convert string to integer (taking account of signs in string)
 *
 * @s: string to convert
 * Return: converted integer value
 *
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
 * Return: 0 if same, neg if s1 < s2, pos if s1 > s2
 *
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
