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

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		if (getline(&line, &size, stdin) == -1)
		{
			free(line);
			printf("\n");
			return (0);
		}

		line[strcspn(line, "\n")] = '\0';

		if (line[0] != '\0')
			execute_command(line);
	}

	return (0);
}
