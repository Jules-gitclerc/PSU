/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** check_map
*/

#include "sokoban.h"

int check_how_many_o(char **map)
{
    int a = 0;
    int b;
    int count = 0;

    while (map[a]) {
        b = 0;
        while (map[a][b]) {
            if (map[a][b] == 'O')
                count++;
            b++;
        }
        a++;
    }
    return (count);
}

int check_how_many_x(char **map)
{
    int a = 0;
    int b;
    int count = 0;

    while (map[a]) {
        b = 0;
        while (map[a][b]) {
            if (map[a][b] == 'X')
                count++;
            b++;
        }
        a++;
    }
    return (count);
}

int check_valid_map(char *buffer)
{
    int i = 0;
    char c;
    int x = 0;
    int o = 0;

    while (buffer[i]) {
        c = buffer[i];
        if (!(c == ' ' || c == '\n' || c == 'O' || c == 'P' || c == 'X' || c == '#'))
            return (-1);
        else if (c == 'X' || c == 'O') {
            if (c == 'X')
                x++;
            else
                o++;
        }
        i++;
    }
    if (o > x)
        return (-1);
    else
        return (1);
}