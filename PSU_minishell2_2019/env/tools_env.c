/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** tools_env
*/

#include <stdlib.h>
#include "env.h"

char *search_env(t_env *env, char *str)
{
    t_env *tmp;
    int i = 0;

    if (env->prev->data == NULL)
        return (NULL);
    tmp = env->next;
    while (tmp != env) {
        i = 0;
        while (str[i] == tmp->data[i]) {
            i++;
            if (tmp->data[i] == '=' && (my_strlen(str) == i))
                return (&tmp->data[i + 1]);
        }
        tmp = tmp->next;
    }
    return (NULL);
}

t_env *update_env(t_env *env, char *dir, char *str)
{
    t_env *tmp;
    int z = 0;
    int i = 0;

    tmp = env->next;
    while (tmp != env) {
        i = 0;
        while (tmp->data[i] == str[i])
            ++i;
        if (tmp->data[i] == '=') {
            i = 0;
            tmp->data = malloc(sizeof(char) * my_strlen(dir) + 2);
            if (tmp->data == NULL)
                exit(84);
            while (dir[z] != '\0') {
                tmp->data[i++] = dir[z++];
                tmp->data[i] = '\0';
            }
            tmp = tmp->next;
        }
    }
    return (tmp);
}

char **conv_list(t_env *env)
{
    t_env *tmp;
    char **tab;
    int i;

    if (env->prev->data == NULL)
        return (NULL);
    tmp = env->next;
    tab = malloc(sizeof(char *) * (count_list(tmp, env) + 1));
    if (tab == NULL)
        exit(84);
    for (i = 0; tmp != env; i++) {
        tab[++i] = my_strdup(tmp->data);
        tmp = tmp->next;
    }
    tab[i] = '\0';
    return (tab);
}

void display_env(t_env *env)
{
    t_env *tmp;

    tmp = env->next;
    while (tmp != env) {
        my_printf("%s\n", tmp->data);
        tmp = tmp->next;
    }
}

void remove_env(t_env *env, char *command)
{
    t_env *tmp;

    tmp = env->next;
    while (tmp != env && my_strcmp(tmp->data, command) != 0)
        tmp = tmp->next;
    if (tmp != env) {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        free(tmp->data);
        free(tmp);
    }
}