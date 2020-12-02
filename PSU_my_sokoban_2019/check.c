/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** check
*/

#include "sokoban.h"

int check_pos_p(char **map, char **tmp)
{
    int a = 0;
    int b;

    while (map[a]) {
        b = 0;
        while (map[a][b]) {
            if (map[a][b] == 'P' && tmp[a][b] == 'O')
                return (1);
            b++;
        }
        a++;
    }
    return (0);
}

int check_win(char **map, char **tmp)
{
    int a = 0;
    int b = 0;

    while (map[a]) {
        b = 0;
        while (map[a][b]) {
            if (check_pos_p(map, tmp) == 1)
                return (0);
            else if (map[a][b] == 'O')
                return (0);
            b++;
        }
        a++;
    }
    return (1);
}

int check_loose(char **map)
{
    int a = 0;
    int b;
    int c = 0;

    while (map[a]) {
        b = 0;
        while (map[a][b]) {
            if (map[a][b] == 'X')
                if ((map[a][b + 1] == '#' && map[a + 1][b] == '#') ||
                    (map[a][b - 1] == '#' && map[a + 1][b] == '#') ||
                    (map[a][b - 1] == '#' && map[a - 1][b] == '#') ||
                    (map[a][b + 1] == '#' && map[a - 1][b] == '#'))
                    c += 1;
            b++;
        }
        a++;
    }
    return (c);
}