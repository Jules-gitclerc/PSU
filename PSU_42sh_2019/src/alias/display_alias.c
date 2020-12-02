/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** display_alias
*/

#include "mysh.h"

int mode_space(char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            len += 1;
    return (len);
}

void display_alias(alias_t *alias)
{
    int len = 0;

    for (alias_t *cur = alias->next; cur != NULL; cur = cur->next) {
        len = mode_space(cur->command);
        if (len == 0)
            my_printf("%s\t%s\n", cur->name, cur->command);
        else
            my_printf("%s\t(%s)\n", cur->name, cur->command);
    }
}

void look_and_display(alias_t *alias, char *catch)
{
    for (alias_t *cur = alias->next; cur != NULL; cur = cur->next)
        if (my_strcmp(catch, cur->name) == 0) {
            my_printf("%s\t(%s)\n", cur->name, cur->command);
            return;
        }
}