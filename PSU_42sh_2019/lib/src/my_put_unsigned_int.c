/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_unsigned_int
*/

#include "my.h"

int my_put_unsigned_int(unsigned int nb)
{
    if (nb < 10)
        my_putchar(48 + nb);
    else {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}
