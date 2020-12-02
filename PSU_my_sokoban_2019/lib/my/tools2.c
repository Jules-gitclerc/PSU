/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** jules.clerc@epitech.eu
*/

#include <stdarg.h>
#include "my.h"

void my_printf_nbr_hex(va_list *list)
{
    int nbr = va_arg(*list, int);

    my_putnbr_base(nbr, "0123456789ABCDEF");
}

void my_printf_nbr_binary(va_list *list)
{
    int nbr = va_arg(*list, int);

    my_putnbr_base(nbr, "01");
}

int my_put_insigned_int(unsigned int nb)
{
    if (nb < 10)
        my_putchar(nb + 48);
    else
    {
        my_put_insigned_int(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}

void my_printf_nbr_u(va_list *list)
{
    unsigned int nbr = va_arg(*list, unsigned int);

    my_put_insigned_int(nbr);
}

void my_printf_nbr_p(va_list *list)
{
    unsigned long int nbr = va_arg(*list, unsigned long int);

    my_putstr("0x");
    my_putnbr_base(nbr, "0123456789abcdef");
}