/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** tools_env
*/

#include "mysh.h"

void destroy_env_list(env_t *env)
{
    env_t *cur = env;
    env_t *next = env->next;

    while (next != NULL) {
        cur = next;
        next = next->next;
        free (cur->line);
        free (cur);
    }
    free (env);
}
