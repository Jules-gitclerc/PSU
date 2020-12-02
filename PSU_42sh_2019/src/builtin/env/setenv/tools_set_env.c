/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** tools_set_env
*/

#include "mysh.h"

int count_nb_arg(char **com)
{
    int nb = 0;

    for (int i = 0; com[i] != NULL; i++, nb++);
    if (nb >= 4) {
        my_printf("setenv: Too many arguments.\n");
        return (-1);
    }
    return (0);
}

int check_input_setenv(char **com)
{
    if (count_nb_arg(com) == -1)
        return (-1);
    for (int i = 0; com[1][i] != '\0'; i++) {
        if ((com[1][i] >= '0' && com[1][i] <= '9')) {
            my_printf("setenv: Variable name must begin with a letter.\n");
            return (-1);
        }
    }
    for (int i = 0; com[1][i] != '\0'; i++) {
        if (com[1][i] == '=') {
            my_printf("setenv: Variable name must contain");
            my_printf(" alphanumeric characters.\n");
            return (-1);
        }
    }
    return (0);
}
