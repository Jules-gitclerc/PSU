/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** PSU_my_printf_2019
*/

#include "my.h"
#include <stdarg.h>
#include <unistd.h>

void double_pourcent(char *src, int i)
{
    my_putchar('%');
}

int findindex(char *tab, char element)
{
    int index = 0;

    for (index = 0; tab[index] != 0; index++) {
        if (tab[index] == element)
            return (index);
    }
    return (-1);
}

int display1(char *src, int i)
{
    if (src[i] != '%')
        write (1, &src[i], 1);
    else
        my_putchar(src[i]);
    i += 1;
    return (i);
}

int sp(char *src, int i)
{
    int n = 0;
    i += 1;
    while (src[i] == ' ') {
        n++;
        i++;
    }
    return (n == 0 ? n + 1 : n + 1);
}

int my_printf(char *src, ...)
{
    void (*tabPrintf[13]) (va_list *) = {my_printf_str, my_printf_nbr,
                my_printf_char, my_printf_nbr_octal, my_printf_nbr_hex,
                my_printf_nbr_hexa, my_printf_nbr_u, my_printf_nbr_binary,
                double_pourcent, my_printf_p, my_printf_sp, my_printf_nbr};
    char tabflags[14] = {'s', 'i', 'c', 'o', 'x', 'X', 'u', 'b', '%',
                        'p', 'S', 'd', 0};
    va_list list;
    int tmpIndex = 0;

    va_start(list, src);
    for (int i = 0; src[i] != 0; i += 0) {
        if (src[i] == '%' && findindex(tabflags, src[i + sp(src, i)]) != -1) {
            tmpIndex = findindex(tabflags, src[i + sp(src, i)]);
            if (tmpIndex != -1)
                (*tabPrintf[tmpIndex]) (&list);
            i += 2;
        }
        else
            i = display1(src, i);
    } return (0);
}
