#include "shell.h"

void which_help(char *command)
{
	char alias[] = "alias help\n";
	char cd[] = "cd help\n";
	char env[] = "env help\n";
	char exit[] = "exit help\n";
	char help[] = "help help\n";
	char setenv[] = "setenv help\n";
	char unsetenv[] = "unsetenv help\n";
	char no_match[] = "no match found\n";

	if (_strcmp(command, "alias") == 0)
		write(STDOUT_FILENO, alias, _strlen(alias));
	else if (_strcmp(command, "cd") == 0)
		write(STDOUT_FILENO, cd, _strlen(cd));
	else if (_strcmp(command, "env") == 0)
		write(STDOUT_FILENO, env, _strlen(env));
	else if (_strcmp(command, "exit") == 0)
		write(STDOUT_FILENO, exit, _strlen(exit));
	else if (_strcmp(command, "help") == 0)
		write(STDOUT_FILENO, help, _strlen(help));
	else if (_strcmp(command, "setenv") == 0)
		write(STDOUT_FILENO, setenv, _strlen(setenv));
	else if (_strcmp(command, "unsetenv") == 0)
		write(STDOUT_FILENO, unsetenv, _strlen(unsetenv));
	else
		write(STDOUT_FILENO, no_match, _strlen(no_match));
}
