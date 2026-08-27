#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t size = 0;
	pid_t pid;
	char *argv[2];

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
			fflush(stdout);
		}

		if (getline(&line, &size, stdin) == -1)
		{
			free(line);
			if (isatty(STDIN_FILENO))
				printf("\n");
			return (0);
		}

		line[strcspn(line, "\n")] = '\0';

		if (line[0] == '\0')
			continue;

		argv[0] = line;
		argv[1] = NULL;

		pid = fork();

		if (pid == -1)
		{
			perror("./hsh");
			continue;
		}

		if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("./hsh");
				exit(127);
			}
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
