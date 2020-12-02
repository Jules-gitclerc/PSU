/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** my_env
*/

#include <stdio.h>
#include "env.h"
#include "my.h"

char my_env(char **command, t_env *env)
{
    if (command[1] != NULL)
        my_printf("env : Too many arguments\n");
    else if (env != NULL)
        display_env(env);
    return (0);
}