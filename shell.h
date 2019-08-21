#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* see if program exists in path directories */
void search_path(char **args, char **env);
char *_getenv(const char *name, char **env);

/* command execution functions */
int execute(char **args);

/* string functions */
char **strtow(char *str, char c);
int count_words(char *str, char c);
int _strlen(const char *s);
char *_strstr(char *haystack, const char *needle);
char *_strchr(char *s, char c);

char *str_concat(char *s1, char *s2);
char *_strdup(char *str);

#endif /* SHELL_H */
