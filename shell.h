#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* command execution functions */
int execute(char **args);

/* string functions */
char **strtow(char *str, char c);
int count_words(char *str);
int _strlen(const char *s);
char *_strstr(char *haystack, const char *needle);
char *_strchr(char *s, char c);



#endif /* SHELL_H */
