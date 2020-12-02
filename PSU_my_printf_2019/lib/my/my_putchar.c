/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_putchar.c
*/
#include <unistd.h>

void    my_putchar(char c)
{
    write(1, &c, 1);
}