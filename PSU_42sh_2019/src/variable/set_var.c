/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** add_var
*/

#include "mysh.h"

void change_env_set_var(var_t *var, int i, char *name, char *enviro)
{
    var_t *cur = var->next;

    for (int o = 0; cur != NULL && o < i; o++, cur = cur->next);
    free (cur->line);
    if (enviro == NULL)
        cur->line = my_strcat(name, "\0");
    else
        cur->line = my_strcat(my_strcat(name, " "), enviro);
}

void add_new_var(var_t *var, char *name, char *enviro)
{
    var_t *cur = var;

    for (; cur->next != NULL; cur = cur->next);
    cur->next = malloc(sizeof(var_t));
    cur = cur->next;
    cur->next = NULL;
    if (enviro == NULL)
        cur->line = my_strcat(name, "\0");
    else
        cur->line = my_strcat(my_strcat(name, " "), enviro);
}

int search_exist_var(const char *name, var_t *var, char **com)
{
    int nb = 0;
    int i = 0;

    for (var_t *cur = var->next; cur != NULL; cur = cur->next, i++) {
        for (int i2 = 0; cur->line[i2] == name[nb]; i2++, nb++);
        if (nb == my_strlen(name)) {
            change_env_set_var(var, i, com[0], com[1]);
            return (i);
        } else
            nb = 0;
    }
    return (-1);
}

void my_set(env_t *env, char *input, shell_t *shell)
{
    char **com = my_str_to_word_array(input, ' ');
    int act = 0;
    char **tmp;

    (void)env;
    if (com[1] == NULL) {
        display_set(shell->var);
        return;
    }
    for (int i = 1; com[i] != NULL; i++) {
        tmp = my_str_to_word_array(com[i], '=');
        if (check_input_set(tmp[0]) == -1)
            return;
        act = search_exist_var(tmp[0], shell->var, tmp);
        if (act == -1)
            add_new_var(shell->var, tmp[0], tmp[1]);
        free_double_tab(tmp);
    }
    free_double_tab(com);
}
