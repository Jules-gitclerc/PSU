/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** moove_tetris
*/

#include "tetris.h"

char **moove_right(char **map, int end_map, int col_max, key_p *key)
{
    for (; end_map > 0; end_map--)
        for (int i = col_max; i > 0; i--)
            if (map[end_map][i + 1] != '|' && map[end_map][i + 1] != 'X'
                && map[end_map][i] == '*')
                my_swap(&map[end_map][i], &map[end_map][i + 1]);
    return (map);
}

char **moove_left(char **map, int end_map, int col_max, key_p *key)
{
    for (; end_map > 0; end_map--)
        for (int i = 0; map[end_map][i] != '\0'; i++)
            if (map[end_map][i - 1] != '|' && map[end_map][i - 1] != 'X'
            && map[end_map][i] == '*')
                my_swap(&map[end_map][i], &map[end_map][i - 1]);
    return (map);
}

char **pause_tetris(char **map, int end_map, int col_max, key_p *key)
{
    int press;

    while (1) {
        print_map(map);
        mvprintw(10, 10, "%s\n", "PAUSE");
        refresh();
        press = getch();
        if (press == key->pause)
            break;
    }
    mvprintw(10, 10, "%s\n", "     ");
    return (map);
}

char **exit_game(char **map, int end_map, int col_max, key_p *key)
{
    endwin();
    my_printf("Your score is %i point\n", key->score);
    exit (0);
    return (map);
}