#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
extern char **environ;


int _putchar(char c);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _printf(char *str);

char **tokizer(char *string);
char *_read_buffer(void);
void free_2d_arr(char **arr);
int exec(char *command[], char **av);
#endif
