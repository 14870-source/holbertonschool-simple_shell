#include "shell.h"

/**
 * execute_command - Executes a command
 * @argv: Array containing command and arguments
 *
 * Return: Exit status of the command
 */
int execute_command(char **argv)
{
	pid_t pid;
	char *path;
	int status;

	path = find_command(argv[0]);

	if (path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		return (127);
	}

	pid = fork();

	if (pid == -1)
	{
		perror("./hsh");
		free(path);
		return (1);
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
		wait(&status);
	}

	free(path);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (1);
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
