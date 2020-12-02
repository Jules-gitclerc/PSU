/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game
*/

#include "navy.h"

int global;

char **creat_map(char **map)
{
    int max = 8;

    map = malloc(sizeof(char *) * max + 1);
    if (map == NULL)
        return (NULL);
    map[max] = NULL;
    for (int i = 0; i < max; i++) {
        map[i] = malloc(sizeof(char) * 9);
        if (map[i] == NULL)
            return (NULL);
        map[i][8] = '\0';
        for (int o = 0; o < 8; o++)
            map[i][o] = '.';
    }
    return (map);
}

void signal_co(int sig, siginfo_t *info, void *ucontext)
{
    global = info->si_pid;
}

int init_first_playeur(struct playeur_one *p_o, char *filepath)
{
    p_o->map_p = creat_map(p_o->map_p);
    p_o->map_e = creat_map(p_o->map_e);
    if (p_o->map_p == NULL || p_o->map_e == NULL)
        return (84);
    p_o->map_p = fill_info_in_map(filepath, p_o->map_p);
    if (p_o->map_p == NULL)
        return (84);
    return (0);
}

int start_game(struct playeur_one *p_o, int ac, char **av)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_co;
    sigaction(SIGUSR1, &sa, NULL);
    if (ac == 2) {
        if (init_first_playeur(p_o, av[1]) == 84)
            return (84);
        start_client();
        p_o->pid = global;
    } else if (ac == 3) {
        if (init_first_playeur(p_o, av[2]) == 84)
            return (84);
        if (start_serveur(my_getnbr(av[1])) == 84)
            return (84);
        p_o->pid = my_getnbr(av[1]);
    } else
        return (84);
    return (0);
}
