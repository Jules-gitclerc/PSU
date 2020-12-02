/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_str_isnum
*/
#include <stdio.h>

int     my_str_isnum(char const *str)
{
    int i = 0;
    if (str == NULL || str[0] == '\0')
        return (0);
    while (str[i]) {
        if ('0' <= str[i] && str[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}