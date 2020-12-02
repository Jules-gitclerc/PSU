/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** my_supergetnbr
*/

#include <stdlib.h>

void my_putchar(char c);

char *my_revstr(char *str);

int count(int nb)
{
    int i = 0;
    int u = 0;
    int great = 1;

    if (nb < 0) {
        nb  = nb * -1;
        u++;
    }
    while (great <= nb) {
        great = great * 10;
        i++;
    }
    i = i + u;
    return (i);
}

char *my_supergetnbr(int nb)
{
    int number_carat = count(nb);
    char *u = malloc(sizeof(char) * number_carat + 1);
    int i = 0;
    int new_nb = 0;

    u[number_carat] = '\0';
    if (nb < 0)
        new_nb = nb * -1;
    else
        new_nb = nb * 1;
    while (i < number_carat) {
        u[i] = (new_nb % 10) + 48;
        i++;
        new_nb = new_nb/10;
    }
    if (nb < 0)
        u[i - 1] = '-';
    u = my_revstr(u);
    return (u);
}
