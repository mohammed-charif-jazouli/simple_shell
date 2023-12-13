#include "shell.h"

/**
 * tokenize - Tokenize a string into an array of tokens.
 * @input: The input string to tokenize.
 *
 * Return: An array of token strings.
 */
char **tokenize(char *input)
{
    char *token = NULL, *token_cp = NULL;
    char **cmd = NULL;
    int count = 0, i = 0;

    if (input == NULL)
        return NULL;

    token_cp = _strdup(input);
    token = strtok(token_cp, SPECIF);

    while (token)
    {
        count++;
        token = strtok(NULL, SPECIF);
    }

    free(token_cp);

    cmd = malloc(sizeof(char *) * (count + 1));

    if (cmd == NULL)
    {
        free(input);
        return NULL;
    }

    token = strtok(input, SPECIF);

    while (token)
    {
        cmd[i] = _strdup(token);
        token = strtok(NULL, SPECIF);
        i++;
    }

    free(input);
    cmd[i] = NULL;

    return cmd;
}

/**
 * free_array - Free memory allocated for an array of strings.
 * @ary: The array of strings to free.
 */
void free_array(char **ary)
{
    int i;

    if (ary == NULL)
        return;

    for (i = 0; ary[i]; i++)
    {
        free(ary[i]);
        ary[i] = NULL;
    }

    free(ary);
    ary = NULL;
}