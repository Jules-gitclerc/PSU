/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** tools3
*/

#include "my.h"
#include <stdlib.h>

void check_back_slash(char const *format, int d)
{
    if (format[d] == '\n' || format[d] == '\a' || format[d] == '\b'
        || format[d] == '\t' || format[d] == '\v' || format[d] == '\f'
        || format[d] == '\r')
        my_putchar(format[d]);
}

int i_like_cs(char const *format, int d)
{
    d++;
    while (format[d] == '%') {
        my_putchar('%');
        d++;
    }
    while (format[d] == ' ') {
        my_putchar(' ');
        d++;
    }
    my_putchar(format[d]);
    d++;
    return (d);
}

int print_printf(char const *format, void (*pointeur[10])(va_list),
                int d, va_list arg)
{
    int locate = 0;

    for (int p = 0; my_count_number_pourcent(format) != p; p++) {
        d = print_carat(format, d);
        if (format[d] == '%' && format[d + 1] == '%')
            d = i_like_cs(format, d);
        else {
            locate = flags(format, d);
            if (locate == 84)
                return (84);
            pointeur[locate](arg);
            d = d + 2;
        }
    }
    d = print_carat(format, d);
    check_back_slash(format, d);
    return (0);
}
