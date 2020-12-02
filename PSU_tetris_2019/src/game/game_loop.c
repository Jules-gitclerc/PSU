/*
** EPITECH PROJECT, 2019
** Tetris_Project
** File description:
** game_loop.c
*/

#include "tetris.h"

void print_map(char **map)
{
    int row = 0;
    int col = 0;
    int number_n = 0;

    for (; map[number_n] != NULL; number_n++);
    getmaxyx(stdscr, row, col);
    row = (row - (number_n / 2) * 2) / 2;
    for (int i = 0; i < number_n; i++, row++)
        mvprintw(row, (col - my_strlen(map[i])) / 2, "%s\n", map[i]);
}

char **to_incorporate_tetris_in_map(char **map, char **tetris, key_p *key)
{
    int col_insert = ((key->colum + 2) / 2) - 1;

    for (int i = 0; tetris[i] != NULL; i++) {
        for (int o = 0; tetris[i][o] != '\0' && map[i + 1][col_insert] != '|';
            o++, col_insert++) {
            if (map[i + 1][col_insert] == 'X') {
                endwin();
                my_printf("GAME OVER\nYour score is %i point\n", key->score);
                exit (0);
            }
            map[i + 1][col_insert] = tetris[i][o];
        }
        col_insert = ((key->colum + 2) / 2) - 1;
    }
    return (map);
}

int check_line_full(char **map)
{
    int count = 0;

    for (int i = 1; map[i] != NULL; i++) {
        for (int o = 0; map[i][o] != '\0'; o++)
            if (map[i][o] == 'X')
                count += 1;
        if (count == my_strlen(map[i]) - 2)
            return (i);
        else
            count = 0;
    }
    return (-1);
}

int ges_key(char **map, key_p *key)
{
    int press[5] = {key->left, key->right, key->pause, key->quit, 0};
    char **(*fct[4])(char **map, int end_map, int col_max,
        key_p *key) = {moove_left, moove_right, pause_tetris, exit_game};
    int preg = getch();

    keypad(stdscr, TRUE);
    for (int i = 0; press[i] != 0; i++) {
        if (press[i] == 1 && preg == KEY_UP)
            map = fct[i](map, key->line + 1, key->colum + 1, key);
        if (press[i] == 2 && preg == KEY_DOWN)
            map = fct[i](map, key->line + 1, key->colum + 1, key);
        if (press[i] == 3 && preg == KEY_RIGHT)
            map = fct[i](map, key->line + 1, key->colum + 1, key);
        if (press[i] == 4 && preg == KEY_LEFT)
            map = fct[i](map, key->line + 1, key->colum + 1, key);
        if (press[i] == preg)
            map = fct[i](map, key->line + 1, key->colum + 1, key);
    }
    return (0);
}

void game_loop(key_p *key, trimino_d *mino)
{
    int k = 0;
    s_game game;

    init_game(&game, key, mino);
    key->score = 0;
    initscr();
    noecho();
    game.map = to_incorporate_tetris_in_map(game.map, game.tetris, key);
    while (1) {
        print_map(game.map);
        refresh();
        game.map = moving_forward(game.map, key->line + 1);
        game.act = check_end_moove(game.map);
        game_loop2(key, mino, &game);
        if ((k = check_line_full(game.map)) > 0)
            game.map = suppr_line(game.map, k, key);
        display_score(key);
        k = ges_key(game.map, key);
    }
    endwin();
}
