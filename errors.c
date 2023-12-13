#include "shell.h"

/**
 * print_error - Print an error message to standard error.
 * @argv_0: The program name.
 * @cmd: The command causing the error.
 * @indx: The index of the command in the input.
 */
void print_error(char *argv_0, char *cmd, int indx)
{
    char *index, mesg[] = ": not found\n";

    index = int_to_ascii(indx);

    write(STDERR_FILENO, argv_0, _strlen(argv_0));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, index, _strlen(index));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, mesg, _strlen(mesg));

    free(index);
}

/**
 * exit_error - Handle and display error messages in the custom shell.
 * @cmd: An array of command arguments.
 * @argv: An array of the program's arguments.
 * @indx: An integer representing an index.
 */
void exit_error(char **cmd, char **argv, int indx)
{
    char *index, mesg[] = ": exit: Illegal number: ";

    index = int_to_ascii(indx);
    write(STDERR_FILENO, argv[0], _strlen(argv[0]));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, index, _strlen(index));
    write(STDERR_FILENO, mesg, _strlen(mesg));
    write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
    write(STDERR_FILENO, "\n", 1);

    free(index);
}