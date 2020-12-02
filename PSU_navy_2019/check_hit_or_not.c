/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** check_hit_or_not
*/

#include "navy.h"

char **add_hit_or_not(char **map, int nb, char *input)
{
    int col = input[0] - 65;
    int line = (input[1] - 48) - 1;

    if (nb == 1)
        map[line][col] = 'x';
    else
        map[line][col] = 'o';
    return (map);
}

int check_it_or_not(char *input, char **map)
{
    int col = input[0] - 65;
    int line = (input[1] - 48) - 1;

    my_printf("%s: ", input);
    if (map[line][col] != '.') {
        my_printf("hit\n");
        return (1);
    } else {
        my_printf("missed\n");
        return (0);
    }
}

int check_win(char **map)
{
    int nb = 0;

    for (int i = 0; map[i] != NULL; i++)
        for (int o = 0; map[i][o] != '\0'; o++)
            if (map[i][o] - 48 > 0 && map[i][o] - 48 < 9)
                nb++;
    if (nb >= 1)
        return (-1);
    else
        return (0);
}