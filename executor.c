#include "shell.h"

/**
 * execute_command - Execute a command.
 * @cmd: The array of command and arguments.
 * @argv: The program's arguments.
 * @count: Number of forks.
 * @indx: The index of the command in the input.
 *
 * Return: The exit status of the executed command.
 */
int execute_command(char **cmd, char **argv, int count, int indx)
{
    char *full_cmd;
    pid_t child;
    int status;

    full_cmd = get_full_path(cmd[0]);

    if (!full_cmd)
    {
        print_error(argv[0], cmd[0], indx);
        free_array(cmd);
        return 127;
    }

    child = fork();
    count++;

    if (child == 0)
    {
        if (execve(full_cmd, cmd, environ) == -1)
        {
            free(full_cmd);
            free_array(cmd);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        free_array(cmd);
        free(full_cmd);
    }

    return WEXITSTATUS(status);
}