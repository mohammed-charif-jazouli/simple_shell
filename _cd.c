#include "shell.h"

/**
 * _cd - Change the current working directory to the target directory.
 *
 * @target_dir: The path to the target directory.
 *
 * Return: 0 on success, 1 on failure.
 */

int _cd(const char *target_dir)
{
    char current_dir[1024];

    /* Get the current working directory */
    if (getcwd(current_dir, sizeof(current_dir)) == NULL)
    {
        write(STDERR_FILENO, "cd", 2);
        return 1;
    }

    setenv("OLDPWD", current_dir, 1);

    /* Change to the target directory */
    if (chdir(target_dir) != 0)
    {
        write(STDERR_FILENO, "cd", 2);
        return 1;
    }

    /* Update the PWD environment variable */
    setenv("PWD", target_dir, 1);

    return 0;
}
