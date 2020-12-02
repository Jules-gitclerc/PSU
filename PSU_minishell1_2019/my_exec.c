/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_exec
*/

#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *rec_execve(char **path, char **command, char **env, int i)
{
    char *name = NULL;

    if (command[0][0] != '/')
        name = my_custom_strcat(path[i++], command[0], 1);
    if (name != NULL) {
        execve(name, command, env);
    } else
        return (NULL);
}

char my_exec(char **command, t_list *env, char *path)
{
    char **envp = NULL;
    int status;
    pid_t pid = fork();
    int i = 0;

    if (pid == -1)
        exit(0);
    else if (pid == 0) {
        envp = conv_list(env);
        rec_execve(my_str_custom_array(path, ':'), command, envp, i);
        my_free(command);
        my_free(envp);
    }
    wait(&status);
    return (0);
}