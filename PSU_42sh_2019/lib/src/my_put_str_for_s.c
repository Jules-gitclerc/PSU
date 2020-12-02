/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_str_for_s
*/

#include <stdio.h>
#include "my.h"
#include <stdlib.h>

int loc(char *str)
{
    int u = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 32 || str[i] >= 127)
            u++;
    return (u);
}

void octal(char c)
{
    int	res[3] = {0, 0, 0};
    int nb = c - 48;

    for (int i = 2; nb > 0; i--) {
        res[i] = nb % 8;
        nb = nb / 8;
    }
    for (int i = 0; i < 3; i++)
        my_put_nbr(res[i]);
}

int my_put_s(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] - 48) < 32 || (str[i] -48) >= 127) {
            my_putchar('\\');
            octal(str[i]);
        } else
            my_putchar(str[i]);
    }
    return (0);
}
