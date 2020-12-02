/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** tools_in_game.c
*/

#include "tetris.h"

char **stone_statue(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        for (int o = 0; map[i][o] != '\0'; o++)
            if (map[i][o] == '*')
                map[i][o] = 'X';
    return (map);
}

int check_end_moove(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        for (int o = 0; map[i][o] != '\0'; o++)
            if (map[i][o] == '*' &&
            (map[i + 1][o] == '-' || map[i + 1][o] == 'X'))
                return (1);
    return (0);
}

char **moving_forward(char **map, int end_map)
{
    for (; end_map > 0; end_map--)
        for (int i = 0; map[end_map][i] != '\0'; i++)
            if (map[end_map][i] == '*')
                my_swap(&map[end_map][i], &map[end_map + 1][i]);
    return (map);
}

char **select_trimino(trimino_d *mino)
{
    int nb_trimino = 0;
    int random = 0;
    int i = 0;
    trimino_d *cur = mino->next;

    for (trimino_d *last = mino->next;
        last != NULL; last = last->next, nb_trimino++);
    random = rand()%nb_trimino;
    while (1) {
        for (; cur != NULL && i < random; cur = cur->next)
            i++;
        if (cur->error == 0)
            break;
        else {
            random = rand()%nb_trimino;
            cur = mino->next;
            i = 0;
        }
    }
    return (cur->triminos);
}

void display_score(key_p *key)
{
    mvprintw(8, 1, "/");
    mvprintw(8, 15, "\\");
    mvprintw(12, 1, "\\");
    mvprintw(12, 15, "/");
    for (int i = 1; i < 14; i++) {
        mvprintw(8, 1 + i, "-");
    	mvprintw(12, 1 + i, "-");
    }
    for (int i = 1; i < 4; i++) {
    	mvprintw(8 + i, 15, "|");
    	mvprintw(8 + i, 1, "|");
    }
    mvprintw(10, 3, "Score");
    mvprintw(10, 9, "%d", key->score);
}