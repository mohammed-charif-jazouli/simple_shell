#include "shell.h"

/**
 * get_environment_variable - Get the value of an environment variable.
 * @var: The name of the environment variable.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *get_environment_variable(char *var)
{
    char *env, *env_copy, *key, *value;
    int i;

    for (i = 0; environ[i]; i++)
    {
        env_copy = _strdup(environ[i]);
        key = strtok(env_copy, "=");

        if (_strcmp(key, var) == 0)
        {
            value = strtok(NULL, "\n");
            env = _strdup(value);
            free(env_copy);
            return env;
        }

        free(env_copy);
        env_copy = NULL;
    }

    return NULL;
}

/**
 * print_environment - Print the environment variables to the standard output.
 * @cmd: The command and arguments.
 * @status: The status variable to set.
 */
void print_environment(char **cmd, int *status)
{
    int i;

    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }

    free_array(cmd);
    *status = 0;
}