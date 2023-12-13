#include "shell.h"

/**
 * _get_path - Get the full path to an executable command.
 * @cmd: The name of the command.
 *
 * Return: The full path to the command or NULL if not found.
 */

char *_get_path(char *cmd)
{
	char *path_env, *pathpluscmd, *dir;
	int i;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	dir = strtok(path_env, ":");
	while (dir)
	{
		pathpluscmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (pathpluscmd)
		{
			_strcpy(pathpluscmd, dir);
			_strcat(pathpluscmd, "/");
			_strcat(pathpluscmd, cmd);
			if (stat(pathpluscmd, &st) == 0)
			{
				free(path_env);
				return (pathpluscmd);
			}
			free(pathpluscmd), pathpluscmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
