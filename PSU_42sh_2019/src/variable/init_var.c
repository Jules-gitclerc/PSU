/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** init_var
*/
#include "mysh.h"

int init_var(shell_t *shell)
{
    shell->var = malloc(sizeof(var_t));
    if (shell->var == NULL)
        return (84);
    shell->var->n = 0;
    shell->var->line = NULL;
    shell->var->next = NULL;
    return (0);
}