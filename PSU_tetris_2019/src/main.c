/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include "tetris.h"

int main(int ac, char **av)
{
    trimino_d *mino = malloc(sizeof(trimino_d));
    key_p key;
    int indic = parsing_arg(&key, av);

    open_floder(mino);
    check_comp(mino);
    if (indic == 1)
        print_debug_mode(mino, &key);
    srand(time(0));
    game_loop(&key, mino);
    return (0);
}
