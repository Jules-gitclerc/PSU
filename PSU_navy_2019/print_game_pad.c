/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** print_game_pad
*/

#include "navy.h"

void print_game_pad(char **map_p, char **map_e)
{
    my_printf("my positions:\n");
    display_map(map_p);
    my_printf("\nenemy’s positions:\n");
    display_map(map_e);
}

void print_wait(void)
{
    my_putchar('\n');
    my_printf("waiting for enemy’s attack...\n");
}
