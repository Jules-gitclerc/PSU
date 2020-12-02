/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** its is a die
*/
#include <stdio.h>

int my_getnbr(char const *str)
{
    int i = 0;
    int u = 1;
    int y = 0;
    int over;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            u = u * -1;
        i++;
    }
    while ((str[i] <= '9' && str[i] >= '0') && str[i]) {
        over = y;
        y = y * 10 + (str[i] - 48);
        if (y == 214748364 && str[i + 1] == '8' && u > 0)
            return (0);
        if (y / 10 != over && y != -2147483648)
            return (0);
        i++;
    }
    return (y * u);
}
