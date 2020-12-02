/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** unset_var
*/

#include "mysh.h"

void delete_node_var(var_t *var, int i)
{
    var_t *target = var;
    var_t *cur = var;

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

int search_exist_unset(const char *name, var_t *var)
{
    int nb = 0;
    int i = 0;

    for (var_t *cur = var->next; cur != NULL; cur = cur->next, i++) {
        for (int i2 = 0; cur->line[i2] == name[nb]; i2++, nb++);
        if (nb == my_strlen(name)) {
            delete_node_var(var, i);
            return (i);
        } else
            nb = 0;
    }
    return (-1);
}

void my_unset_var(env_t *env, char *input, shell_t *shell)
{
    char **com = my_str_to_word_array(input, ' ');

    (void)env;
    if (com[1] == NULL) {
        my_printf("unset: Too few arguments.\n");
        return;
    }
    search_exist_unset(com[1], shell->var);
    free_double_tab(com);
}