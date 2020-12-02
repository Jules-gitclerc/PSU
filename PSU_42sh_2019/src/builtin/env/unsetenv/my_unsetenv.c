/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** my_unsetenv
*/

#include "mysh.h"

void delete_node(env_t *env, int i)
{
    env_t *target = env->next;
    env_t *cur = env->next;

    int o = 0;
    for (; o < i - 1; o++) {
        target = target->next;
        cur = cur->next;
    }
    target = target->next;
    cur->next = cur->next->next;
    free (target->line);
    free (target);
}

int search_exist_unsetenv(const char *name, env_t *env)
{
    int nb = 0;
    int i = 0;

    for (env_t *cur = env->next; cur != NULL; cur = cur->next, i++) {
        for (int i2 = 0; cur->line[i2] == name[nb]; i2++, nb++);
        if (nb == my_strlen(name)) {
            delete_node(env, i);
            return (i);
        } else
            nb = 0;
    }
    return (-1);
}

void my_unsetenv(env_t *env, char *input, shell_t *shell)
{
    char **com = my_str_to_word_array(input, ' ');

    (void)shell;
    if (com[1] == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
        return;
    }
    search_exist_unsetenv(com[1], env);
    free_double_tab(com);
}
