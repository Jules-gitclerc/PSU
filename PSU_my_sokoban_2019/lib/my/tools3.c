/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** jules.clerc@epitech.eu
*/

#include "my.h"
#include <stdarg.h>

void    my_octal(int nb)
{
    int tab[3] = {0, 0, 0};
    int i = 2;
    int res;

    while (nb > 10) {
        res = nb % 8;
        nb = nb / 8;
        tab[i] = res;
        i -= 1;
    }
    my_put_nbr(tab[0]);
    my_put_nbr(tab[1]);
    my_put_nbr(tab[2]);
}

void my_printf_s(va_list *list)
{
    char *str = va_arg(*list, char *);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] - 48 > 32 && str[i] - 48 < 127) {
            my_putchar(str[i]);
        }
        else {
            my_putchar('\\');
            my_octal(str[i]);
        }
        i++;
    }
}

void  my_hexa_supp(unsigned long int nbr)
{
    int res;

    if (nbr >= 16) {
        res = nbr % 16;
        my_hexa_supp(nbr / 16);
    }
    else if (nbr > 0) {
        res = nbr % 16;
    }
    if (res > 9)
        my_putchar(res + 87);
    else
        my_putchar(res + 48);
}

void my_printf_p(va_list *list)
{
    unsigned long int nbr = va_arg(*list, unsigned long int);

    my_putstr("0x");
    my_hexa_supp(nbr);
}

int check_space(char *src, int i)
{
    while (src[i] != '%') {
        if (src[i] != ' ' || src[i] != '%')
            return (0);
        i--;
    }
    return (1);
}
