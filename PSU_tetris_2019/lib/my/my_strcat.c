/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** lib
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int nb = my_strlen(dest) + my_strlen(src);
    int i = 0;
    char *new = malloc(sizeof(char) * nb + 1);

    if (new == NULL)
        return (NULL);
    new[nb] = '\0';
    for (int o = 0; dest[o] != '\0'; o++, i++)
        new[i] = dest[o];
    for (int o = 0; src[o] != '\0'; o++, i++)
        new[i] = src[o];
    return (new);
}
