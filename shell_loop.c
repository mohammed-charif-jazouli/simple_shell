#include "shell.h"

/**
 * shell_loop - Function containing the loop for the simple shell.
 *
 * @argv: List of arguments.
 *
 * Return: Status of the shell exit.
 */
int shell_loop(char **argv)
{
    char *line = NULL, **cmd = NULL;
    int status = 0, indx = 0, count = 1;

    while (1)
    {
        line = read_line();

        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            fflush(stdout);
            return status;
        }

        indx++;
        cmd = tokenize(line);

        if (cmd != NULL)
        {
            if (is_builtin_command(cmd[0]))
                handle_builtin_commands(cmd, argv, &status, indx);
            else
            {
                status = execute_command(cmd, argv, count, indx);
            }
        }
    }
}