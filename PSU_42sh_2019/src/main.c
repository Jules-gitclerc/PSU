/*
** EPITECH PROJECT, 2019
** my_lib_C
** File description:
** main.c
*/

#include "mysh.h"

int main(int ac, char **av, char **envp)
{
    env_t *env = malloc(sizeof(env_t));

    (void)ac;
    (void)av;
    fill_env(envp, env);
    loop_shell(env);
    return (0);
}
