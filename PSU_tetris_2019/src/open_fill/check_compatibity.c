/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** check_compatibity
*/

#include "tetris.h"

void check_colum_comp(trimino_d *cur)
{
    int nb_col = 0;

    for (nb_col = 0; cur->triminos[0][nb_col] != '\0'; nb_col++);
    if (nb_col != cur->nb_colum)
        cur->error = 1;
}

void check_line_comp(trimino_d *cur)
{
    int nb_line = 0;

    for (nb_line = 0; cur->triminos[nb_line] != NULL; nb_line++);
    if (nb_line != cur->nb_line)
        cur->error = 1;
}

void check_comp(trimino_d *mino)
{
    for (trimino_d *cur = mino->next; cur != NULL; cur = cur->next) {
        if (cur->error != 1) {
            check_line_comp(cur);
            check_colum_comp(cur);
        }
    }
}