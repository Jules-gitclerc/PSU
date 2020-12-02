/*
** EPITECH PROJECT, 2020
** my_lib_C
** File description:
** tools_my_printf3
*/

#include "my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void print_double_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}

void pourcent_t(va_list arg)
{
    print_double_tab(va_arg(arg, char **));
}
