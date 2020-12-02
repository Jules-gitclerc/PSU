/*
** EPITECH PROJECT, 2020
** my_lib_C
** File description:
** my_clear_str
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

char *empty_space(char *str)
{
    int i = 0;
    int y = 0;
    int tmp = 0;
    char *new = NULL;

    for (; str[i] == ' ' || str[i] == '\t'; i++);
    if (str[i] == '\0')
        return (NULL);
    tmp = i;
    for (; str[i] != '\0'; i++, y++);
    new = malloc(sizeof(char) * y + 1);
    new[y] = '\0';
    for (int i2 = 0; str[tmp] != '\0'; i2++, tmp++)
        new[i2] = str[tmp];
    return (new);
}

int count_space_for_clean_str(char *str)
{
    int i = 0;
    int count = 0;
    int number_space = 0;

    while (i != my_strlen(str)) {
        for (; str[i] != ' ' && str[i] != '\t' && str[i] != '\0'; i++, count++);
        for (; (str[i] == ' ' || str[i] == '\t') && str[i] != '\0'; i++);
        if (i == my_strlen(str))
            break;
        number_space++;
    }
    return (number_space + count);
}

char *my_clean_str(char *str)
{
    int i = 0;
    int count = 0;
    char *new = NULL;
    int number_space = 0;

    if ((str = empty_space(str)) == NULL)
        return (NULL);
    number_space = count_space_for_clean_str(str);
    new = malloc(sizeof(char) * number_space + 1);
    new[number_space] = '\0';
    while (i < my_strlen(str)) {
        for (; str[i] != ' ' && str[i] != '\t' && str[i] != '\0'; i++, count++)
            new[count] = str[i];
        for (; (str[i] == ' ' || str[i] == '\t') && str[i] != '\0'; i++);
        if (i == my_strlen(str))
            break;
        new[count] = ' ';
        count++;
    }
    return (new);
}
