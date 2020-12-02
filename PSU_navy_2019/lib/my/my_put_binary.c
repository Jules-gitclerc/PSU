/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_binary
*/

#include "my.h"

void my_putchar(char lettre);

int my_put_binary(int nb)
{
    if (nb < 2)
        my_putchar(48 + nb);
    if (nb >= 2) {
        my_put_binary(nb / 2);
        my_putchar(nb % 2 + 48);
    }
    return (0);
}
