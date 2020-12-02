/*
** EPITECH PROJECT, 2019
** piscine
** File description:
** my_putchar
*/
#include <unistd.h>

void    my_putchar(char c)
{
    write(1, &c, 1);
}