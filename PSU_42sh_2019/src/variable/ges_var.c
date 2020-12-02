/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** ges_var
*/

#include "mysh.h"

void display_set(var_t *var)
{
    for (var_t *cur = var->next; cur != NULL; cur = cur->next)
        my_printf("%s\n", cur->line);
}