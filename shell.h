#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

/* command execution functions */
int execute(char **args);

/* string functions */
char **strtow(char *str, char c);
int count_words(char *str);
int _strlen(const char *s);
char *_strstr(char *haystack, const char *needle);
char *_strchr(char *s, char c);

/* builtin functions and handlers */
/**
 * struct cmd_s - used to identify a built-in to execute
 * @type: an existing built-in function
 * @exec_built_in: directs to built-in function for execution
 */
typedef struct cmd_s
{
	char *type;
	int (*exec_built_in)(char **args);
} cmd_t;
int (*get_built_in(char *cmd))(char **args);
int simple_exit(char **args);
int simple_env(char **args);
int simple_unsetenv(char **args);
int simple_setenv(char **args);
int not_built_in(char **args);

#endif /* SHELL_H */
