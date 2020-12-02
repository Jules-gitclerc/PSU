/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_strlen
*/

#include <stdio.h>

int     my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}