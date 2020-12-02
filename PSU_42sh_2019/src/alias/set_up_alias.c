/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** set_up_alias
*/

#include "mysh.h"

int init_alias(shell_t *shell)
{
    shell->alias = malloc(sizeof(alias_t));
    if (shell->alias == NULL)
        return (84);
    shell->alias->command = NULL;
    shell->alias->name = NULL;
    shell->alias->next = NULL;
    return (0);
}