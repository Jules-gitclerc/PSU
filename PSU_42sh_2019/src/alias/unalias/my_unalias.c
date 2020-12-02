/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_unalias
*/

#include "mysh.h"

void delete_node_alias(alias_t *alias, int i)
{
    alias_t *target = alias->next;
    alias_t *cur = alias;

    int o = 0;
    for (; o < i; o++) {
        target = target->next;
        cur = cur->next;
    }
    cur->next = cur->next->next;
    free (target->command);
    free (target->name);
    free (target);
}

void ges_loc_suppr(char *str, alias_t *alias)
{
    alias_t *cur = alias->next;
    int i = 0;

    for (; cur != NULL; cur = cur->next, i++)
        if (my_strcmp(cur->name, str) == 0) {
            delete_node_alias(alias, i);
            return;
        }
}

void my_unalias(env_t *env, char *input, shell_t *shell)
{
    char **com = my_str_to_word_array(input, ' ');

    (void)env;
    if (com[1] == NULL)
        dprintf(2, "unalias: Too few arguments.\n");
    for (int i = 1; com[i] != NULL; i++)
        ges_loc_suppr(com[i], shell->alias);
    free_double_tab(com);
}