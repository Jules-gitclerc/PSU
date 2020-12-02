/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** op_errors
*/

#include "mysh.h"

int is_at_end(char *command)
{
    int is_op = 0;

    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] != ' ' || command[i] != '\t')
            is_op = 0;
        if (command[i] == '&' && command[i + 1] == '&') {
            is_op = 1;
            i++;
        }
        if (command[i] == '|' && command[i + 1] == '|') {
            is_op = 1;
            i++;
        }
    }
    if (is_op == 1)
        return (84);
    return (0);
}

int is_at_start(char *command)
{
    int is_carac = 0;

    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == '&' && command[i + 1] == '&' && is_carac == 0)
            return (84);
        if (command[i] == '|' && command[i + 1] == '|' && is_carac == 0)
            return (84);
        if (command[i] != ' ' || command[i] != '\t')
            is_carac = 1;
    }
    return (0);
}

int check_wrong_operators(char *command)
{
    if (my_strcmp(command, "||") == 0) {
        my_printf("Invalid null command.\n");
        return (84);
    }
    if (my_strcmp(command, "&&") == 0)
        return (0);
    if (is_at_start(command) == 84) {
        my_printf("Invalid null command.\n");
        return (84);
    }
    if (is_at_end(command) == 84) {
        my_printf("Invalid null command.\n");
        return (84);
    }
    return (0);
}

int check_op_errors(char *command)
{
    char *tab_error[5] = {"|| ||", "&& &&", "|| &&", "&& ||", 0};

    if (check_wrong_operators(command) == 84)
        return (84);
    for (int i = 0; tab_error[i] != 0; i++) {
        if (my_strcmp_carat(tab_error[i], command) == 1) {
            my_printf("Invalid null command.\n");
            return (84);
        }
    }
    return (0);
}