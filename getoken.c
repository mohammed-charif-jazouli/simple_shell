#include "shell.h"

/**
 * getoken - Tokenize a string into an array of tokens.
 * @returned_line: The input string to tokenize.
 *
 * Return: An array of token strings.
 */

char **getoken(char *returned_line)
{
	char *token = NULL, *tokencp = NULL;
	char **cmd = NULL;
	int cont = 0, i = 0;

	if (!returned_line)
		return (NULL);
	tokencp = _strdup(returned_line);
	token = strtok(tokencp, SPECIF);
	if (token == NULL)
	{
		free(returned_line), returned_line = NULL;
		free(tokencp), tokencp = NULL;
		return (NULL);
	}
	while (token)
	{
		cont++;
		token = strtok(NULL, SPECIF);
	}
	free(tokencp), tokencp = NULL;

	cmd = malloc(sizeof(char *) * (cont + 1));
	if (!cmd)
	{
		free(returned_line), returned_line = NULL;
		return (NULL);
	}
	token = strtok(returned_line, SPECIF);
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, SPECIF);
		i++;
	}
	free(returned_line), returned_line = NULL;
	cmd[i] = NULL;
	return (cmd);
}

/**
 * freearray - Free memory allocated for an array of strings.
 * @ary: The array of strings to free.
 */

void freearray(char **ary)
{
	int i;

	if (!ary)
		return;

	for (i = 0; ary[i]; i++)
		{
		free(ary[i]);
		ary[i] = NULL;
	}

	free(ary), ary = NULL;
}
