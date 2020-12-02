/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** decrypt_signal
*/

#include <stdlib.h>
#include <stdio.h>
#include "navy.h"

char convert_signal_1(int nb)
{
    char tab[9] = "#ABCDEFGH";

    nb = nb / 10;
    return (tab[nb]);
}

char convert_signal_2(int nb)
{
    nb = nb / 10;
    if (nb <= 4)
        return (nb + 48);
    else
        return ((nb - 1) + 48);
}
