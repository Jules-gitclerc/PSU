/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** Compare the string with n how paramenter.
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] == s2[i] && i <= n; i++);
    if (i == my_strlen(s1))
        return (0);
    return (1);
}
