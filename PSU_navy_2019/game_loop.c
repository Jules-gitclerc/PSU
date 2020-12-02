/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/

#include "navy.h"

int glo = 0;

void catch_game(int sig)
{
    glo = sig;
}

void recup_loop1(struct playeur_one *p_o, char *str)
{
    int recup = 0;

    while (glo != 12) {
        recup += glo;
        kill(p_o->pid, SIGUSR1);
        pause();
    }
    str[0] = convert_signal_1(recup);
        recup = 0;
    while (glo != 10) {
        recup += glo;
        kill(p_o->pid, SIGUSR2);
        pause();
    }
    str[1] = convert_signal_2(recup);
    if (check_it_or_not(str, p_o->map_p) == 1)
        kill(p_o->pid, SIGUSR1);
    else
        kill(p_o->pid, SIGUSR2);
    p_o->map_p = modify_map(p_o->map_p, str);
}

void send_loop(struct playeur_one *p_o)
{
    int i = 0;

    i = convert_intput(p_o);
    for (int o = 0; o < i; o++) {
        kill(p_o->pid, SIGUSR1);
        pause();
    }
    i = convert_input_nb(p_o);
    for (int o = 0; o < i; o++) {
        kill(p_o->pid, SIGUSR2);
        pause();
    }
    kill(p_o->pid, SIGUSR1);
    pause();
    check_recup(glo, p_o);
    p_o->map_e = modify_map_recup(p_o->map_e, p_o->input, glo);
}

int play_usr_one(struct playeur_one *p_o)
{
    char *str = malloc(sizeof(char) * 2);

    str[2] = '\0';
    signal(SIGUSR1, catch_game);
    signal(SIGUSR2, catch_game);
    print_game_pad(p_o->map_p, p_o->map_e);
    while (1) {
        if (take_imput_line(p_o) == -1)
            return (0);
        send_loop(p_o);
        print_wait();
        pause();
        recup_loop1(p_o, str);
        my_putchar('\n');
        print_game_pad(p_o->map_p, p_o->map_e);
    }
    free(str);
}

int play_usr_two(struct playeur_one *p_o)
{
    char *str = malloc(sizeof(char) * 2);

    str[2] = '\0';
    signal(SIGUSR1, catch_game);
    signal(SIGUSR2, catch_game);
    print_game_pad(p_o->map_p, p_o->map_e);
    print_wait();
    while (1) {
        recup_loop1(p_o, str);
        if (take_imput_line(p_o) == -1)
            return (0);
        send_loop(p_o);
        my_putchar('\n');
        print_game_pad(p_o->map_p, p_o->map_e);
        print_wait();
        pause();
    }
    free(str);
}