/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** signal
*/

#include "navy.h"

void start_client(void)
{
    int pid = getpid();

    my_printf("my_pid: %i\nwaiting for enemy connection...\n", pid);
    pause();
    my_printf("\nenemy connected\n\n");
}

int start_serveur(int pid)
{
    int i = 0;

    i = kill(pid, SIGUSR1);
    if (i == -1) {
        my_printf("Bad pid, please put a good pid\n");
        return (84);
    }
    my_printf("my_pid: %i\n", getpid());
    my_printf("successfully connected\n\n");
    return (0);
}
