/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** fct_signal
*/

#include "mysh.h"

void signal_ctrl_c(int sig)
{
    char *pwd = recup_pwd();

    (void)sig;
    my_putchar('\n');
    my_printf("\033[34;01m%s$> \033[00m", pwd);
    free (pwd);
}
