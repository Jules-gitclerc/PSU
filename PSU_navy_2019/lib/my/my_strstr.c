/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** Reproduce the behavior of function.
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int locat = 0;
    int delta = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == to_find[0]) {
            delta = i;
            locat = 0;
            for (; str[delta] == to_find[locat]; delta++, locat++);
            if (delta == my_strlen(to_find))
                return (&str[i]);
        }
    return ("mdr");
}
