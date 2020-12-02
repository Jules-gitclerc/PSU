/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** tools_my_printf
*/

#include "my.h"
#include <stdio.h>
#include <stdarg.h>

void pourcent_c(va_list arg)
{
    my_putchar(va_arg(arg, int));
}

void pourcent_s(va_list arg)
{
    my_putstr(va_arg(arg, char *));
}

void pourcent_i(va_list arg)
{
    my_put_nbr(va_arg(arg, int));
}

void pourcent_o(va_list arg)
{
    my_put_octal(va_arg(arg, int));
}

void pourcent_hexa(va_list arg)
{
    my_put_hexa(va_arg(arg, int));
}
