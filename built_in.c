#include "shell.h"

/**
 * is_builtin_command - Check if a command is a built-in command.
 * @cmd: The command to check.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int is_builtin_command(char *cmd)
{
    char *builtins[] = {
        "exit", "env", "setenv", "unsetenv", "cd", NULL
    };
    int i;

    for (i = 0; builtins[i]; i++)
    {
        if (_strcmp(cmd, builtins[i]) == 0)
            return 1;
    }

    return 0;
}

/**
 * handle_builtin_commands - Handle built-in commands.
 * @cmd: The array of command and arguments.
 * @argv: The program's arguments.
 * @status: The status variable to set.
 * @indx: The index of the command in the input.
 */
void handle_builtin_commands(char **cmd, char **argv, int *status, int indx)
{
    if (_strcmp(cmd[0], "exit") == 0)
        exit_shell(cmd, argv, status, indx);
    else if (_strcmp(cmd[0], "env") == 0)
        print_environment(cmd, status);
    else if (_strcmp(cmd[0], "cd") == 0)
    {
        if (_strcmp(cmd[1], "-") == 0)
            change_directory("..");
        else
            change_directory(cmd[1]);
    }
}

/**
 * exit_shell - Handle the "exit" built-in command.
 * @cmd: The array of command and arguments.
 * @argv: The program's arguments.
 * @status: The status variable to set.
 * @indx: The index of the command in the input.
 */
void exit_shell(char **cmd, char **argv, int *status, int indx)
{
    int exit_status = *status;

    if (cmd[1])
    {
        if (is_positive_number(cmd[1]))
            exit_status = _atoi(cmd[1]);
        else
        {
            exit_error(cmd, argv, indx);
            free_array(cmd);
            *status = 2;
            return;
        }
    }

    free_array(cmd);
    exit(exit_status);
}