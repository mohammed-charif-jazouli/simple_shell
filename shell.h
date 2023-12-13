#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define SPECIF " \t\r\a\n"
extern char **environ;

/* Built-in functions */
void exit_shell(char **cmd, char **argv, int *status, int indx);
void print_environment(char **cmd, int *status);
int change_directory(const char *target_dir);

/* Tool functions */
char *read_line(void);
int shell_loop(char **argv);
char **tokenize(char *input);
char *get_full_path(char *cmd);
char *get_environment_variable(char *var);
int execute_command(char **cmd, char **argv, int count, int indx);
void print_error(char *argv_0, char *cmd, int indx);
int is_builtin_command(char *cmd);
void handle_builtin_commands(char **cmd, char **argv, int *status, int indx);
void exit_error(char **cmd, char **argv, int indx);

/* String handler functions */
char *_strdup(const char *s);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *int_to_ascii(int n);
void reverse_string(char *str, int len);
int is_positive_number(const char *s);
int _atoi(const char *s);

/* Memory functions */
void free_array(char **ary);

#endif /* _SHELL_H_ */