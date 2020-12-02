/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/

#include "navy.h"

int main(int ac, char **av)
{
    struct playeur_one p_o;

    if (ac < 2)
        return (84);
    if (tireh(av[1]) == 1)
        return (0);
    if (start_game(&p_o, ac, av) == 84)
        return (84);
    if (ac == 2) {
        if (play_usr_one(&p_o) == 84)
            return (84);
    } else {
        if (play_usr_two(&p_o) == 84)
            return (84);
    }
    return (0);
}
