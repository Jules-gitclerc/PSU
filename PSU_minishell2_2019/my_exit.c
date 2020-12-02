/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** my_exit
*/

#include "env.h"
#include "mysh.h"
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char check_exit(char **command)
{
    int nb = 0;

        for (nb = 0; command[nb]; nb++);
    if (command[1] != NULL)
        for (int i = 0; command[1][i] != '\0'; i++)
            if ((command[1][i] >= '!' && command[1][i] < '-')
                || (command[1][i] > '-' && command[1][i] < '0')
                || (command[1][i] > '9' && command[1][i] <= '~'))
                return (1);
    if (my_printf_nbr > 2)
        return (1);
    return (0);
}

char my_exit(char **command, t_env *env)
{
    t_env *env2;
    int status = 0;

    if (check_exit(command) == -1)
        return (0);
    if (command[1] != NULL)
        status = my_getnbr(command[1]);
    if (env != NULL) {
        env2 = env->next;
        while (env2 != env) {
            free(env->data);
            env2 = env2->next;
        }
        free(env2);
    }
    my_free(command);
    exit(status);
    return (0);
}