#include "shell.h"

/**
 * main - simple shell main function.
 *
 * @argc: count of args.
 * @argv: list of arguments.
 *
 * Return: always 0 succes.
*/
int main(int argc, char **argv)
{
	int status = 0;

	(void) argc;

	status = shell_looper(argv);

	return (status);
}
