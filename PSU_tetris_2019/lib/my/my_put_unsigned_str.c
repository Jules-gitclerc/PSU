/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_unsigned_str
*/

#include "my.h"

int my_put_unsigned_str(unsigned char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        my_putchar(str[n]);
        n++;
    }
    return (0);
}