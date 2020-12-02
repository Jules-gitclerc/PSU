/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** modify_map
*/

#include "navy.h"

char **modify_map(char **map, char *input)
{
    char tab[8] = "ABCDEFGH";
    int i = -1;

    while (tab[++i] != input[0]);

    if (map[(input[1] - 48) - 1][i] == '.')
        map[(input[1] - 48) - 1][i] = 'o';
    else
        map[(input[1] - 48) - 1][i] = 'x';
    return (map);
}

char **modify_map_recup(char **map, char *input, int glo)
{
    char tab[8] = "ABCDEFGH";
    int i = -1;

    while (tab[++i] != input[0]);
    if (glo == 10)
        map[(input[1] - 48) - 1][i] = 'x';
    else
        map[(input[1] - 48) - 1][i] = 'o';
    return (map);
}