/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main
*/

#include "my.h"
#include "sokoban.h"
#include <ncurses.h>

int option(char *av)
{
    if (av[1] == 'h') {
        my_putstr("USAGE\n");
        my_printf("\t./my_sokoban map\n");
        my_putstr("DESCRIPTION\n");
        my_printf("\tmap  file representing the warehouse map, ");
        my_putstr("containing '#' for walls,\n");
        my_printf("\t\t'P' for the player, 'X' for boxes and 'O' for storage ");
        my_putstr("locations.\n");
        return (0);
    }
    else
        return (84);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-')
            return(option(av[1]));
        open_file(av[1]);
    } else
        return (84);
    return (0);
}