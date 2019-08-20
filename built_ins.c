#include "shell.h"

/**
 *
 *
 *
 */
int simple_exit(char **args)
{
	(void) args;

	printf("I am a banana\n");
	return (0);
}

/**
 *
 *
 *
 */
int not_built_in(char **args)
{
	(void) args;

	printf("I do not exist\n");
	return (1);
}
