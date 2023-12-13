#include "shell.h"

/**
 * return_line - Read a line of input from the user.
 *
 * Return: Pointer to the read line.
 */

char *return_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t i;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	i = getline(&line, &len, stdin);
	if (i == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
