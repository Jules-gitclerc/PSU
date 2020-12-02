/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_exit
*/

#include "minishell.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

char my_exit(char **str, t_list *env)
{
    unsigned int i = 0;
    int nb = 0;

    (void)env;
    for (; str[nb]; nb++);
    if (nb != 2)
        my_printf("exit: Expression Syntax.\n");
    else if (str[1] == NULL) {
        my_printf("exit\n");
        exit(0);
    }
    else {
        for (int i = 0; str[1][i] != '\0'; i++) {
            if (!(str[1][i] >= 0 && str[1][i] <= 9)) {
                my_printf("Badly formed number.\n");
                exit(1);
            }
        }
        i = my_getnbr(str[1]);
        my_printf ("exit\n");
    }
    exit(i);
}