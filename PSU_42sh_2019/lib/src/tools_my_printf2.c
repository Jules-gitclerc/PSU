/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** tools_my_printf2
*/

#include "my.h"
#include <stdio.h>
#include <stdarg.h>

void pourcent_hexa_capit(va_list arg)
{
    my_put_hexa_capitalize(va_arg(arg, int));
}

void pourcent_b(va_list arg)
{
    my_put_binary(va_arg(arg, int));
}

void pourcent_u(va_list arg)
{
    my_put_unsigned_int(va_arg(arg, int));
}

void pourcent_p(va_list arg)
{
    my_put_pointeur(va_arg(arg, unsigned long int));
}

void pourcent_ss(va_list arg)
{
    my_put_s(va_arg(arg, char *));
}
