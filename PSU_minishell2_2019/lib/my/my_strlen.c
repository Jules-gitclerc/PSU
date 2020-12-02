/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_strlen
*/

#include <stdio.h>

int     my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] && str[i] != '\0')
        i++;
    return (i);
}