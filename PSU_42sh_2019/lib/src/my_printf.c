/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdarg.h>

int error(char const *format)
{
    if (my_strlen(format) < 1)
        return (84);
    return (0);
}

int check_not_pourcent(const char *format)
{
    if (my_count_number_pourcent(format) == 0) {
        for (int i = 0; format[i] != '\0'; i++)
            my_putchar(format[i]);
        return (0);
    }
    return (1);
}

int print_carat(char const *format, int i)
{
    if (error(format) == 84)
            return (84);
    while (format[i] != '%') {
        if (format[i] == '\0')
            return (0);
        my_putchar(format[i]);
        i++;
    }
    while (format[i + 1] == ' ')
        i++;
    return (i);
}

int flags(char const *format, int u)
{
    char flags[13] = {'s', 'i', 'c', 'o', 'x',
                        'X', 'b', 'u', 'p', 'S', 'd', 't', 0};
    int i = 0;

    u++;
    while (flags[i] != format[u]) {
        if (flags[i] == 0)
            return (84);
        i++;
    }
    return (i);
}

int my_printf(const char *format, ...)
{
    va_list arg;
    va_start(arg, format);
    int d = 0;
    void (*pointeur[12]) (va_list) = {pourcent_s, pourcent_i, pourcent_c, \
                                    pourcent_o, pourcent_hexa, \
                                    pourcent_hexa_capit, pourcent_b,
                                    pourcent_u, pourcent_p, pourcent_ss,
                                    pourcent_i, pourcent_t};

    if (check_not_pourcent(format) == 0)
        return (0);
    print_printf(format, pointeur, d, arg);
    va_end(arg);
    return (d);
}
