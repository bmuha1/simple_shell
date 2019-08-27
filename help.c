#include "shell.h"

/**
 * which_help - display info about builtins
 * @command: builtin commands
 */
void which_help(char *command)
{
	char cd[] = "cd: Change the shell working directory.\n";
	char env[] = "env: Display the environmental variables.\n";
	char exit[] = "exit: Exit the shell.\n";
	char help[] = "help: Display information about builtin commands.\n";
	char setenv[] = "setenv: Set an environmental variable.\n";
	char unsetenv[] = "unsetenv: Unset an environmental variable.\n";
	char no_match[] = ": no help topics match '";
	char no_match2[] = "'. Try 'help help'.\n";

	if (_strcmp("cd", command) == 0)
		write(STDOUT_FILENO, cd, _strlen(cd));
	else if (_strcmp("env", command) == 0)
		write(STDOUT_FILENO, env, _strlen(env));
	else if (_strcmp("exit", command) == 0)
		write(STDOUT_FILENO, exit, _strlen(exit));
	else if (_strcmp("help", command) == 0)
		write(STDOUT_FILENO, help, _strlen(help));
	else if (_strcmp("setenv", command) == 0)
		write(STDOUT_FILENO, setenv, _strlen(setenv));
	else if (_strcmp("unsetenv", command) == 0)
		write(STDOUT_FILENO, unsetenv, _strlen(unsetenv));
	else
	{
		write(STDOUT_FILENO, command, _strlen(command));
		write(STDOUT_FILENO, no_match, _strlen(no_match));
		write(STDOUT_FILENO, command, _strlen(command));
		write(STDOUT_FILENO, no_match2, _strlen(no_match2));
	}
}
