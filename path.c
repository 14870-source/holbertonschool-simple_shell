#include "shell.h"

/**
 * get_path - Gets the PATH environment variable
 *
 * Return: Pointer to PATH value, or NULL if not found
 */
char *get_path(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
	}

	return (NULL);
}

/**
 * find_command - Finds a command executable in PATH
 * @command: Command to search for
 *
 * Return: Allocated full path, or NULL if command is not found
 */
char *find_command(char *command)
{
	char *path, *path_copy, *dir, *full_path;
	size_t len;

	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
		{
			full_path = malloc(strlen(command) + 1);
			if (full_path == NULL)
				return (NULL);

			strcpy(full_path, command);
			return (full_path);
		}
		return (NULL);
	}

	path = get_path();
	if (path == NULL)
		return (NULL);

	path_copy = malloc(strlen(path) + 1);
	if (path_copy == NULL)
		return (NULL);

	strcpy(path_copy, path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		len = strlen(dir) + strlen(command) + 2;
		full_path = malloc(len);

		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
