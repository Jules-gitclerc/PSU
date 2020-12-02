/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_str_isupper
*/
#include <stdio.h>

int     my_str_isupper(char const *str)
{
    int i = 0;
    if (str == NULL || str[0] == '\0')
        return (0);
    while (str[i]) {
        if ('A' <= str[i] && str[i] <= 'Z')
            i++;
        else
            return (0);
    }
    return (1);
}