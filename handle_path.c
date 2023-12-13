#include "shell.h"

/**
 * get_full_path - Get the full path to an executable command.
 * @cmd: The name of the command.
 *
 * Return: The full path to the command or NULL if not found.
 */
char *get_full_path(char *cmd)
{
    char *path_env, *path_plus_cmd, *dir;
    int i;
    struct stat st;

    for (i = 0; cmd[i]; i++)
    {
        if (cmd[i] == '/')
        {
            if (stat(cmd, &st) == 0)
                return _strdup(cmd);
            return NULL;
        }
    }

    path_env = get_environment_variable("PATH");

    if (path_env == NULL)
        return NULL;

    dir = strtok(path_env, ":");

    while (dir)
    {
        path_plus_cmd = malloc(_strlen(dir) + _strlen(cmd) + 2);

        if (path_plus_cmd)
        {
            _strcpy(path_plus_cmd, dir);
            _strcat(path_plus_cmd, "/");
            _strcat(path_plus_cmd, cmd);

            if (stat(path_plus_cmd, &st) == 0)
            {
                free(path_env);
                return path_plus_cmd;
            }

            free(path_plus_cmd);
            path_plus_cmd = NULL;
            dir = strtok(NULL, ":");
        }
    }

    free(path_env);
    return NULL;
}