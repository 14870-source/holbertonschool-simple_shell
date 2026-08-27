#include "shell.h"

/**
 * execute_command - Executes a command
 * @command: The command to execute
 *
 * Return: Nothing
 */
void execute_command(char *command)
{
	pid_t pid;
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	pid = fork();

	if (pid == -1)
	{
		perror("./hsh");
		return;
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
