/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** pipe
*/

#include <fcntl.h>
#include <stdio.h>
#include "mysh.h"
#include "my.h"
#include <unistd.h>

void close_pipe(int *pipe)
{
    if (pipe != NULL)
        for (int i = 0; pipe[i] != 0; i++)
            close(pipe[i]);
}

int my_pipe(t_command *command)
{
    (command->input != -1) ? dup2(command->input, 0) : (0);
    (command->output != -1) ? dup2(command->output, 1) : (0);
    return (0);
}