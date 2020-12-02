/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** jules.clerc@epitech.eu
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

void my_printf_str(va_list *list)
{
    char *src = va_arg(*list, char *);

    write(1, src, my_strlen(src));
}

void my_printf_char(va_list *list)
{
    char c = va_arg(*list, int);

    write (1, &c, 1);
}

void    my_printf_nbr(va_list *list)
{
    int nbr = va_arg(*list, int);

    my_put_nbr(nbr);
}

void    my_printf_nbr_octal(va_list *list)
{
    int nbr = va_arg(*list, int);

    my_putnbr_base(nbr, "01234567");
}

void    my_printf_nbr_hexa(va_list *list)
{
    int nbr = va_arg(*list, int);

    my_putnbr_base(nbr, "0123456789abcdef");
}