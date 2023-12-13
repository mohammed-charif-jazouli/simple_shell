#include "shell.h"

/**
 * shell_looper - function contains loop for the simple shell
 *
 * @argv: list of arguments
 *
 * Return: status of the exit of shell
 *
 */

int shell_looper(char **argv)
{
	char *line = NULL, **cmd = NULL;
	int status = 0, indx = 0, count = 1;

	while (1)
	{
		line = return_line();
		if (line == NULL)/* EOF ctr + D */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			fflush(stdout);
			return (status);
		}

		indx++;
		cmd = getoken(line);
		if (!cmd)
			continue;
		if (is_builtcmd(cmd[0]))
			_builtcmd(cmd, argv, &status, indx);
		else
		{
			status = _executer(cmd, argv, indx, count);
		}
	}
}
