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
	char *argv[64];
	int argc;

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

		argc = parse_command(line, argv);

		if (argc == 0)
			continue;

		if (strcmp(argv[0], "exit") == 0)
		{
			free(line);
			return (0);
		}

		execute_command(argv);
	}

	return (0);
}
