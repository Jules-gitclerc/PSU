/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** ges_pipe
*/

#include "mysh.h"

char *pipe_proc_children(int pipefd[2], int switch_fd, int i, char **pars_pipe)
{
    char *command = NULL;
    int fd = 0;

    close(pipefd[0]);
    dup2(switch_fd, STDIN_FILENO);
    if (pars_pipe[i + 1] != NULL) {
        dup2(pipefd[1], STDOUT_FILENO);
        command = my_clean_str(pars_pipe[i]);
    } else if ((fd = (ges_left_redirect(pars_pipe[i]))) != -1) {
        command = my_clean_str(recup_com_redirect(pars_pipe[i]));
        dup2(fd, STDOUT_FILENO);
    } else
        command = my_clean_str(pars_pipe[i]);
    return (command);
}

int exce_children_pipe(char *command, env_t *env, shell_t *shell)
{
    int status = 0;
    int len = 0;

    len = pars_command(env, command, shell, 1);
    if (len != 1)
        status = looking_input(env, command, shell);
    free(command);
    exit(status);
}

int ges_wait(char **pars_pipe, pid_t cpid, int status)
{
    char *str[] = {"setenv", "unsetenv", "alias", "set", \
    "exit", "cd", "unset", "unalias", 0};
    int len = 0;

    for (int i = 0; str[i] != 0; i++)
        if (my_strcmp(recup_first_command(pars_pipe[0]), str[i]) == 0)
            len++;
    if (len > 0 && pars_pipe[1] == NULL)
        return (0);
    while (waitpid(cpid, &status, 0) > 0);
    return (status);
}

int pipe_proc(char **pars_pipe, env_t *env, shell_t *shell)
{
    int pipefd[2];
    int status = 0;
    char *command = NULL;
    pid_t cpid;
    int switch_fd = 0;

    if (pars_command(env, pars_pipe[0], shell, 0) == 1)
        status += 1;
    for (int i = status; pars_pipe[i] != NULL; i++) {
        pipe(pipefd);
        cpid = fork();
        if (cpid == 0) {
            command = pipe_proc_children(pipefd, switch_fd, i, pars_pipe);
            exce_children_pipe(command, env, shell);
        }
        close(pipefd[1]);
        if (pars_pipe[i + 1] != NULL) {
            switch_fd = pipefd[0];
            segfault_handling(status);
        }
    }
    return (ges_wait(pars_pipe, cpid, status));
}
