/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_str_isalpha
*/
#include <stdio.h>

int     my_str_isalpha(char const *str)
{
    int i = 0;
    if (str == NULL || str[0] == '\0')
        return (0);
    while (str[i]) {
        if (('a' <= str[i] && str[i] <= 'z') || (65 <= str[i] && str[i] <= 90))
            i++;
        else
            return (0);
    }
    return (1);
}