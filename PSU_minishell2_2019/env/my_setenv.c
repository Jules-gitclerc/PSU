/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** my_setenv
*/

#include <env.h>
#include <stdio.h>
#include "my.h"

char my_setenv(char **command, t_env *env)
{
    int i = 0;

    for (i = 0; command[i]; i++);
    if (i > 3)
        my_printf("setenv: Too many arguments\n");
    else if (command[1] != NULL) {
        remove_env(env, command[1]);
        env = add_env(env, command[2], command[1]);
    }
    else
        my_env(command, env);
    return (0);
}