/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** uti_env
*/

#include "minishell.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int count_list(t_list *chain, t_list *env)
{
    int count = 0;

    for (; chain != env; ++count)
        chain = chain->next;
    return (count);
}

char **conv_list(t_list *env)
{
    t_list *chain;
    char **tab;
    int i = 0;

    if (env->prev->data == NULL)
        return (NULL);
    chain = env->next;
    if ((tab = malloc(sizeof(char *) * (count_list(chain, env) + 1))) == NULL)
        return (NULL);
    while (chain != env) {
        tab[i] = my_strdup(chain->data);
        chain = chain->next;
        i++;
    }
    tab[i] = '\0';
    return (tab);
}

void my_free(char **tab)
{

    if (tab != NULL) {
        for (int i = 0; tab[i] != NULL; i++)
        	free(tab[i]);
        free(tab);
    }
}

char *search_env(t_list *env, char *str)
{
    t_list *chain;
    int i = 0;

    if (env->prev->data == NULL)
        return (NULL);
    chain = env->next;
    while (chain != env) {
        while (str[i] == chain->data[i]) {
            i++;
            if (chain->data[i] == '=' && (my_strlen(str) == i))
                return (&chain->data[i + 1]);
        }
        chain = chain->next;
    }
    return (NULL);
}