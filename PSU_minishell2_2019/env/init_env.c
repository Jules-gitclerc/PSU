/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** init_env
*/

#include "env.h"
#include <stdio.h>
#include <stdlib.h>

t_env *create_node(void)
{
    t_env *node;

    node = malloc(sizeof(t_env));
    if (node == NULL)
        return (NULL);
    node->next = node;
    node->prev = node;
    return (node);
}

t_env *add_env(t_env *env, char *str, char *str2)
{
    t_env *tmp = create_node();
    int i = 0;
    int z = 0;

    tmp->data = malloc(my_strlen(str) + my_strlen(str2) + 2);
    if (tmp->data == NULL)
        return (NULL);
    while (str2 && str2[i] != '\0')
        tmp->data[z++] = str2[i++];
    i = 0;
    tmp->data[z++] = '=';
    while (str && str[i] != '\0')
        tmp->data[z++] = str[i++];
    tmp->data[z] = '\0';
    tmp->prev = env->prev;
    tmp->next = env;
    env->prev->next = tmp;
    env->prev = tmp;
    return (env);
}

t_env *init_listenv(char **env)
{
    t_env *tmp = create_node();
    t_env *tmp2 = NULL;
    int j = 0;

    for (int i = 0; env[i] != NULL; i++) {
        tmp2 = create_node();
        tmp2->data = malloc(my_strlen(env[i]) + 1);
        if (tmp2->data == NULL)
            return (NULL);
        for (j = 0; env[i][j] != '\0'; j++)
            tmp2->data[j] = env[i][j];
        tmp2->data[j] = '\0';
        tmp2->prev = tmp->prev;
        tmp2->next = tmp;
        tmp->prev->next = tmp2;
        tmp->prev = tmp2;
    }
    return (tmp);
}

int count_list(t_env *tmp, t_env *env)
{
    int count = 0;

    while (tmp != env) {
        ++count;
        tmp = tmp->next;
    }
    return (count);
}