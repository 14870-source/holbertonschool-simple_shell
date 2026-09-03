#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

int execute_command(char **argv);
int parse_command(char *line, char **argv);
char *get_path(void);
char *find_command(char *command);
void print_env(void);

#endif
