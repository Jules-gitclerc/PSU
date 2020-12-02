/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] == s2[i] && s2[i] != '\0' && s1[i] != '\0'; i++);
    if (i == my_strlen(s1) && my_strlen(s1) == my_strlen(s2))
        return (0);
    return (1);
}

