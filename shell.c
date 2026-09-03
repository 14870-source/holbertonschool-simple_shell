#include "shell.h"

/**
 * execute_command - Executes a command
 * @argv: Array containing command and arguments
 *
 * Return: Nothing
 */
int execute_command(char **argv)
{
	pid_t pid;
	char *path;

	path = find_command(argv[0]);

	if (path == NULL)
	{
		fprintf(stderr, "./hsh: %s: not found\n", argv[0]);
		return;
	}

	pid = fork();

	if (pid == -1)
	{
		perror("./hsh");
		free(path);
		return;
	}

	if (pid == 0)
	{
		if (execve(path, argv, environ) == -1)
		{
			perror("./hsh");
			free(path);
			exit(127);
		}
	}
	else
	{
		wait(NULL);
	}

	free(path);
}

/**
 * parse_command - Splits a command into arguments
 * @line: Command line
 * @argv: Array to store arguments
 *
 * Return: Number of arguments
 */
int parse_command(char *line, char **argv)
{
	char *token;
	int argc = 0;

	token = strtok(line, " \t");

	while (token != NULL && argc < 63)
	{
		argv[argc] = token;
		argc++;
		token = strtok(NULL, " \t");
	}

	argv[argc] = NULL;

	return (argc);
}
