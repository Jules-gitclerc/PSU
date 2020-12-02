/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_hexa_capitalize
*/

#include "my.h"

int my_put_hexa_capitalize(int nb)
{
    if (nb >= 16)
        my_put_hexa_capitalize(nb / 16);
    if ((nb % 16) > 9)
        my_putchar(nb % 16 + 55);
    else
        my_putchar(nb % 16 + 48);
    return (0);
}
