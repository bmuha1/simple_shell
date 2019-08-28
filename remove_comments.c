#include "shell.h"

/**
 * remove_comments - Remove comments from the line of user input
 * @line: The user input
 */
void remove_comments(char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '#')
		{
			if (i == 0)
			{
				line[i] = '\0';
				break;
			}
			else if (_strchr(" \t\r\n\v\f", line[i - 1]) != '\0')
			{
				line[i] = '\0';
				break;
			}
		}
	}
}
