/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_strdup
*/

#include <stdlib.h>

int     my_strlen(char const *str);

char    *my_strdup(char const *str)
{
    int len = my_strlen(str);
    int i = 0;
    char *dup;

    if ((dup = malloc(sizeof(char) * (len + 1))) == NULL)
        return (NULL);
    while (i < len) {
        dup[i] = str[i];
        i++;
    }
    dup[len] = '\0';
    return (dup);
}