/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_revstr.c
*/

char    *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char tmp;

    while (str[i])
        i++;
    i--;
    while (j < i) {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
        j++;
        i--;
    }
    return (str);
}