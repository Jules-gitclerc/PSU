/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_pointeur
*/

#include "my.h"
#include <stdlib.h>

int display(unsigned long int nb)
{
    if (nb >= 16)
        display(nb / 16);
    if ((nb % 16) > 9)
        my_putchar(nb % 16 + 87);
    else
        my_putchar(nb % 16 + 48);
    return (0);
}

int my_put_pointeur(unsigned long int nb)
{
    if (nb == 0)
        return (84);
    else {
        my_putstr("0x");
        display(nb);
    }
    return (0);
}