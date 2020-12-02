/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** movements
*/

#include "sokoban.h"

struct vector vector;

int get_pos_p(char **map, int *colum, int *line)
{
    int x = 0;
    int y;

    while (map[x]) {
        y = 0;
        while (map[x][y]) {
            if (map[x][y] == 'P') {
                *colum = y;
                *line = x;
                return (0);
            }
            y++;
        }
        x++;
    }
    return (84);
}

void move_up(int col, int line, char **map, char **tmp)
{
    if (line > 0 && map[line - 1][col] != '#') {
        if (map[line - 1][col] == 'X') {
            if (map[line - 2][col] != '#' && map[line - 2][col] != 'X') {
                map[line - 1][col] = 'P';
                if (tmp[line][col] == 'O')
                    map[line][col] = 'O';
                else
                    map[line][col] = ' ';
                map[line - 2][col] = 'X';
            }
        } else {
            map[line - 1][col] = 'P';
            if (tmp[line][col] == 'O')
                    map[line][col] = 'O';
            else
                map[line][col] = ' ';
        }
    }
}

void move_down(int col, int line, char **map, char **tmp)
{
    if (line > 0 && map[line + 1][col] != '#') {
        if (map[line + 1][col] == 'X') {
            if (map[line + 2][col] != '#' && map[line + 2][col] != 'X') {
                map[line + 1][col] = 'P';
                if (tmp[line][col] == 'O')
                    map[line][col] = 'O';
                else
                    map[line][col] = ' ';
                map[line + 2][col] = 'X';
            }
        } else {
            map[line + 1][col] = 'P';
            if (tmp[line][col] == 'O')
                    map[line][col] = 'O';
            else
                map[line][col] = ' ';
        }
    }
}

void move_right(int col, int line, char **map, char **tmp)
{
    if (col > 0 && map[line][col + 1] != '#') {
        if (map[line][col + 1] == 'X') {
            if (map[line][col + 2] != '#' && map[line][col + 2] != 'X') {
                map[line][col + 1] = 'P';
                if (tmp[line][col] == 'O')
                    map[line][col] = 'O';
                else
                    map[line][col] = ' ';
                map[line][col + 2] = 'X';
            }
        } else {
            map[line][col + 1] = 'P';
            if (tmp[line][col] == 'O')
                    map[line][col] = 'O';
            else
                map[line][col] = ' ';
        }
    }
}

void move_left(int col, int line, char **map, char **tmp)
{
    if (line > 0 && map[line][col - 1] != '#') {
        if (map[line][col - 1] == 'X') {
            if (map[line][col - 2] != '#' && map[line][col - 2] != 'X') {
                map[line][col - 1] = 'P';
                if (tmp[line][col] == 'O')
                    map[line][col] = 'O';
                else
                    map[line][col] = ' ';
                map[line][col - 2] = 'X';
            }
        } else {
            map[line][col - 1] = 'P';
            if (tmp[line][col] == 'O')
                map[line][col] = 'O';
            else
                map[line][col] = ' ';
        }
    }
}