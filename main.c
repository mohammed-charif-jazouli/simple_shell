#include "shell.h"

/**
 * main - Simple shell main function.
 *
 * @argc: Count of args.
 * @argv: List of arguments.
 *
 * Return: Always 0 for success.
 */
int main(int argc, char **argv)
{
    int status = 0;

    (void)argc;

    status = shell_loop(argv);

    return status;
}