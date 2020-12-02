/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** parsing
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "env.h"
#include <sys/wait.h>
#include "my.h"

void my_wait(int nb)
{
    for (int status = 0; nb > 0; nb--) {
        if (wait(&status) == -1)
            my_printf("ERROR\n");
        if (WTERMSIG(status) == 11)
            write(2, "Segmentation fault (core dumped)\n", 34);
        if (WIFSTOPPED(status))
            write(2, "Stopped\n", 9);
    }
}

int my_stock_command(t_list *list, t_command *command)
{
    t_command *tmp = malloc(sizeof(t_command));

    if (tmp == NULL)
        exit(84);
    tmp->data = command->data;
    tmp->output = command->output;
    tmp->input = command->input;
    tmp->fd = command->fd;
    tmp->prev = list->last;
    tmp->next = NULL;
    if (list->last)
        list->last->next = tmp;
    else
        list->first = tmp;
    list->last = tmp;
    return (0);
}

void pipe_list (char **tmp, t_list *list, int **my_pipe, int nb_pipe)
{
    t_command *command = malloc(sizeof(t_command));
    int n[2];
    int i = 0;

    if (command == NULL)
        exit(84);
    command->output = -1;
    command->input = -1;
    command->fd = -1;
    for (int j = 0; nb_pipe > 0; j += 2, nb_pipe--) {
        if ((pipe(n)) == -1)
            exit (0);
        command->output = n[1];
        (*my_pipe)[j] = n[0];
        (*my_pipe)[j + 1] = n[1];
        (*my_pipe)[j + 2] = 0;
        command->data = my_str_to_wordtab(tmp[i++], ' ');
        my_stock_command(list, command);
        command->input = n[0];
    }
    command->output = -1;
    command->data = my_str_to_wordtab(tmp[i], ' ');
    my_stock_command(list, command);
}

char *check_pipe(t_list *list, char **tmp, int **pipe)
{
    t_command *command;
    int nb_pipe = -1;

    *(pipe) = NULL;
    for (int i = 0; tmp[i] != NULL; i++)
        nb_pipe++;
    if (nb_pipe > 0) {
        *(pipe) = malloc(sizeof(int) * (nb_pipe * 2 + 1));
        if (pipe == NULL)
            return (NULL);
    }
    pipe_list(tmp, list, pipe, nb_pipe);
    command = list->first;
    return (0);
}

char *parser(char *tab, t_env *env, t_list *list)
{
    t_command *tmp;
    int nb = 0;
    char *result;
    int *pipe;

    result = check_pipe(list, separe_wordtab(tab, '|'), &pipe);
    if (result != 0)
        return (result);
    tmp = list->first;
    while (tmp != NULL) {
        if (my_execve(tmp, env, pipe) != 5)
            nb++;
        tmp = tmp->next;
    }
    close_pipe(pipe);
    my_wait(nb);
    return (0);
}