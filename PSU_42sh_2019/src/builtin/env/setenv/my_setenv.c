/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** my_setenv
*/

#include "mysh.h"

void change_env_set(env_t *env, int i, char *name, char *enviro)
{
    env_t *cur = env->next;

    for (int o = 0; cur != NULL && o < i; o++, cur = cur->next);
    free (cur->line);
    if (enviro == NULL)
        cur->line = my_strcat(my_strcat(name, "="), "\0");
    else
        cur->line = my_strcat(my_strcat(name, "="), enviro);
}

void add_new_env(env_t *env, char *name, char *enviro)
{
    env_t *cur = env->next;

    for (; cur->next != NULL; cur = cur->next);
    cur->next = malloc(sizeof(env_t));
    cur = cur->next;
    cur->next = NULL;
    if (enviro == NULL)
        cur->line = my_strcat(my_strcat(name, "="), "\0");
    else
        cur->line = my_strcat(my_strcat(name, "="), enviro);
}

int search_exist(const char *name, env_t *env, char **com)
{
    int nb = 0;
    int i = 0;

    for (env_t *cur = env->next; cur != NULL; cur = cur->next, i++) {
        for (int i2 = 0; cur->line[i2] == name[nb]; i2++, nb++);
        if (nb == my_strlen(name)) {
            change_env_set(env, i, com[1], com[2]);
            return (i);
        } else
            nb = 0;
    }
    return (-1);
}

void my_setenv(env_t *env, char *input, shell_t *shell)
{
    char **com = my_str_to_word_array(input, ' ');
    int act = 0;

    if (com[1] == NULL) {
        my_env(env, input, shell);
        return;
    }
    if (check_input_setenv(com) == -1)
        return;
    act = search_exist(com[1], env, com);
    if (act == -1)
        add_new_env(env, com[1], com[2]);
    free_double_tab(com);
}
