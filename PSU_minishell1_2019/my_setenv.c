/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** setenv
*/

#include "minishell.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

t_list *create_env(char *s1, char *s2, t_list *env)
{
    t_list	*chain;
    int i = 0;
    int z = 0;

    chain = create_node();
    if ((chain->data = malloc(my_strlen(s1) + my_strlen(s2) + 2)) == NULL)
        return (NULL);
    while (s2 && s2[i] != '\0')
        chain->data[z++] = s2[i++];
    i = 0;
    chain->data[z++] = '=';
    while (s1 && s1[i] != '\0')
        chain->data[z++] = s1[i++];
    chain->data[z] = '\0';
    chain->prev = env->prev;
    chain->next = env;
    env->prev->next = chain;
    env->prev = chain;
    return (env);
}

char my_setenv(char **str, t_list *env)
{
    int i = 0;

    while (str[i])
        i++;
    if (i > 3)
        return (0);
    else if (i == 1)
        my_env(str, env);
    else {
        env = create_env(str[1], str[2], env);
    }
    return (0);
}