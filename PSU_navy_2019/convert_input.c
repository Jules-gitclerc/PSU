/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** convert_input
*/

#include "navy.h"

int convert_intput(struct playeur_one *p_o)
{
    char tab[9] = "#ABCDEFGH";
    int i = 0;

    while (p_o->input[0] != tab[++i]);
    return (i);
}

int convert_input_nb(struct playeur_one *p_o)
{
    return (p_o->input[1] - 48);
}