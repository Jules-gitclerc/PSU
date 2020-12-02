/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_putnbr_base
*/

#include "my.h"

int check_base(char const *base)
{
    int i = 0;
    int j;

    if (my_strlen(base) < 2)
        return (0);
    while (base[i]) {
        if ((base[i] > 31 && base[i] < 48) || (base[i] > 57 && base[i] < 65) ||
            (base[i] > 90 && base[i] < 97) || base[i] > 123)
            return (0);
        j = i + 1;
        while (base[j]) {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int my_putnbr_base(int nbr, char const *base)
{
    int x = my_strlen(base);
    int nbbr = nbr;
    if (check_base(base)) {
        if (nbr < 0) {
            my_putchar('-');
            nbbr = -nbr;
        }
        else
            nbbr = nbr;
        if (nbbr < x)
            my_putchar(base[nbbr]);
        else {
            my_putnbr_base(nbbr / x, base);
            my_putnbr_base(nbbr % x, base);
        }
    }
    return (0);
}