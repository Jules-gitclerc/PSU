/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** tools_game_loop
*/

#include "navy.h"

int send_win(struct playeur_one *p_o, int glo)
{
    print_game_pad(p_o->map_p, p_o->map_e);
    if (check_win(p_o->map_p) == 1) {
        kill(p_o->pid, SIGUSR2);
        my_printf("\nI won\n");
        return (1);
    } else {
        if (glo == 12) {
            my_printf("\nEnemi won\n");
            return (-1);
        }
    }
    return (0);
}

void check_recup(int glo, struct playeur_one *p_o)
{
    if (glo == 10)
        my_printf("%s: hit\n", p_o->input);
    else
        my_printf("%s: missed\n", p_o->input);
}

void send_hit_or_not(char *str, struct playeur_one *p_o)
{
    if (check_it_or_not(str, p_o->map_p) == 1)
        kill(p_o->pid, SIGUSR1);
    else
        kill(p_o->pid, SIGUSR2);
    p_o->map_p = modify_map(p_o->map_p, str);
}