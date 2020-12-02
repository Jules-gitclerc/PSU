/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** lib
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

char *my_strncat(char *dest, char const *src, int nb)
{
    char *str = malloc(sizeof(char) * nb + 1);
    int o = 0;

    if (str == NULL)
        return (NULL);
    for (int i = 0; dest[i] != '\0'; i++, o++)
        str[o] = dest[i];
    for (int i = 0; src[i] != '\0' && i < nb; i++, o++)
        str[o] = src[i];
    str[o] = '\0';
    return (str);
}
