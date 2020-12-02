/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_str_islower
*/
#include <stdio.h>

int     my_str_islower(char const *str)
{
    int i = 0;
    if (str == NULL || str[0] == '\0')
        return (0);
    while (str[i]) {
        if ('a' <= str[i] && str[i] <= 'z')
            i++;
        else
            return (0);
    }
    return (1);
}