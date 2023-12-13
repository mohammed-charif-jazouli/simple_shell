#include "shell.h"

/**
 * read_line - Read a line of input from the user.
 *
 * Return: Pointer to the read line.
 */
char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read_chars;

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);

    read_chars = getline(&line, &len, stdin);
    
    if (read_chars == -1)
    {
        free(line);
        return NULL;
    }

    return line;
}