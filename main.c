#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Exit status
 */
int main(void)
{
	char *line = NULL;
	size_t size = 0;
	char *argv[64];
	int argc;
	int status = 0;

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
			return (status);
		}

		line[strcspn(line, "\n")] = '\0';

		argc = parse_command(line, argv);

		if (argc == 0)
			continue;

		if (strcmp(argv[0], "exit") == 0)
		{
			free(line);
			return (status);
		}

		if (strcmp(argv[0], "env") == 0)
		{
			print_env();
			status = 0;
			continue;
		}

		status = execute_command(argv);
	}

	return (status);
}
