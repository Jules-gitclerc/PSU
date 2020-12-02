/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** tools_set_var
*/

#include "mysh.h"

int check_input_set(char *com)
{
    for (int i = 0; com[i] != '\0'; i++) {
        if (!((com[i] >= 'a' && com[i] <= 'z') ||
        (com[i] >= 'A' && com[i] <= 'Z') || (com[i] >= '0' && com[i] <= '9'))) {
            printf("set: Variable name must contain alphanumeric"
            "characters.\n");
            return (-1);
        }
        else if (!((com[i] >= 'a' && com[i] <= 'z') ||
        (com[i] >= 'A' && com[i] <= 'Z'))) {
            my_printf("set: Variable name must begin with a letter.\n");
            return (-1);
        }
    }
    return (0);
}