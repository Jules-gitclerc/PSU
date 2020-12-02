/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** my_unsetenv
*/

#include <stdio.h>
#include "env.h"

char my_unsetenv(char **command, t_env *env)
{
    int i = 1;

    if (command[i] != NULL)
        while (command[i] != NULL)
            remove_env(env, command[i++]);
    else
        my_printf("unsetenv: Too few arguments.\n");
    return (0);
}