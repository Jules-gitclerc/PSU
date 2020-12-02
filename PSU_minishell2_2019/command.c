/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** command
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mysh.h"
#include "env.h"

int my_command(t_command *command, t_env *env)
{
    char (*function[5])(char **, t_env *) = {my_exit, my_cd, my_env,
    my_unsetenv, my_setenv};
    char *commands[5] = {"exit", "cd", "env", "unsetenv", "setenv"};
    int i = -1;

    while (++i < 5 && my_strcmp(command->data[0], commands[i]) != 0);
    return ((i == 5) ? (5) : function[i](command->data, env));
}

char check_command(t_command *command, t_env *env)
{
    if (command->data[0] == NULL || command->data == NULL)
        return (0);
    return ((my_command(command, env) == 5) ? (5) : (0));
}