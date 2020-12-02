/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_strstr
*/

#include <stdio.h>

char    *my_strstr(char *str, char *to_find)
{
    int i = 0;
    int j = 0;

    if (to_find == NULL || to_find[0] == '\0')
        return (str);
    while (str[i]) {
        while (str[i] == to_find[j] && to_find[j]) {
            i++;
            j++;
        }
        if (to_find[j] == '\0')
            return (str + i - j);
        i -= j;
        j = 0;
        i++;
    }
    return (NULL);
}