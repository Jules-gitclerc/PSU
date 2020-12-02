/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** suppr_line
*/

#include "tetris.h"

char **suppr_line(char **map, int i, key_p *key)
{
    key->score += 118;
    for (int o = 1; map[i][o] != '|'; o++)
        map[i][o] = ' ';
    for (; i > 0; i--)
        for (int o = 0; map[i][o] != '\0'; o++)
            if (map[i][o] == 'X')
                my_swap(&map[i][o], &map[i + 1][o]);
    print_map(map);
    refresh();
    return (map);
}

void init_game(s_game *game, key_p *key, trimino_d *mino)
{
    game->map = init_map(key->line, key->colum);
    game->tetris = select_trimino(mino);
    game->act = 0;
}

void game_loop2(key_p *key, trimino_d *mino, s_game *game)
{
    if (game->act == 1) {
            game->map = stone_statue(game->map);
            game->act = 0;
            game->tetris = select_trimino(mino);
            game->map = to_incorporate_tetris_in_map(game->map,
                                            game->tetris, key);
        }
}