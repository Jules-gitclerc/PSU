/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** env
*/

#include "my.h"
#include "minishell.h"
#include <stdlib.h>

char my_env(char **str, t_list *env)
{
    t_list	*envp;

    if (str[1] != NULL)
        return (0);
    else if (env != NULL) {
        envp = env->next;
        while (envp != env) {
            my_printf("%s\n", envp->data);
            envp = envp->next;
        }
    }
    return (0);
}