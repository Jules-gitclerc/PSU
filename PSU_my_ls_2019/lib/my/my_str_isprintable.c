/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_str_isprintable
*/
#include <stdio.h>

int     my_str_isprintable(char const *str)
{
    int i = 0;
    while (str[i]) {
        if (32 < str[i] && str[i] != 127)
            i++;
        else
            return (0);
    }

    return (1);
}
