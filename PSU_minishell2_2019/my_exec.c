/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** my_exec
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "mysh.h"
#include "env.h"

char test_file(char s1, char s2, char **command)
{
    if (s1 != ' ') {
        if (command[0][0] == s1 && command[0][1] == s2 &&
        (access(command[0], F_OK) != -1))
        return (0);
    } else if (s1 == ' ')
        if (command[0][0] == s2 && (access(command[0], F_OK) != -1))
            return (0);
    return (1);
}

char *check_exec(char **path, char **command, char **tabenv, int i)
{
    char *filename = command[0];

    if (!test_file('.', '/', command)) {
        if ((access(command[0], R_OK | X_OK) == -1) ||
        (execve(filename, command, tabenv) == -1))
            return ("error");
    } else if (command[0][0] != '/' && command[0][0] != '.')
        filename = my_custom_strcat(path[i++], command[0], 1);
    else if (!test_file(' ', '/', command))
        if ((access(command[0], R_OK | X_OK) == -1) ||
        (execve(filename, command, tabenv) == -1))
            return ("error");
    if (filename != NULL) {
        execve(filename, command, tabenv);
        check_exec(path, command, tabenv, i);
    }
    else
        return (NULL);
    return (0);
}

int my_execve(t_command *tab, t_env *env, int *pipe)
{
    char **tab_env;
    char *error;
    pid_t pid;

    if (check_command(tab, env) != 5)
        return (5);
    else if ((pid = fork()) == 0) {
        my_pipe(tab);
        close_pipe(pipe);
        tab_env = conv_list(env);
        error = check_exec(
        my_str_to_wordtab(search_env(env, "PATH"), ':'),
        tab->data, tab_env, 0);
        if (my_strlen(error) == 0)
            my_printf("%s: Command not found\n", tab->data[0]);
        else
            my_printf("%s: Permission Denied\n", tab->data[0]);
        free(tab->data);
        my_free(tab_env);
        exit(84);
    }
    else if (pid == -1)
        exit(84);
    return (0);
}