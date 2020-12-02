/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "mysh.h"
#include "env.h"
#include "my.h"

void my_term(void)
{
    char cwd[256];

    getcwd(cwd, sizeof(cwd));
    my_printf("\033[30;44m~%s$>\033[0m ", cwd);
}

void signal_ctrl_c(int sig)
{
    my_putchar('\n');
    my_term();
}

char minishell(char *buff, t_env *env)
{
    char **tab;
    char *error;
    t_list list;

    (void)(*env);
    list.first = NULL;
    list.last = NULL;
    tab = separe_wordtab(buff, ';');
    for (int i = 0; tab[i]; i++) {
        error = parser(tab[i], env, &list);
        if (error != 0)
            my_printf("%s\n", error);
    }
    my_free(tab);
    return (0);
}

int main(int ac, char **av, char **envp)
{
    t_env *env;
    char *buff = NULL;
    size_t size;
    int input;
    signal(SIGINT, signal_ctrl_c);

    (void)av;
    (void)ac;
    my_term();
    env = init_listenv(envp);
    while (input = getline(&buff, &size, stdin)) {
        if (input == -1)
            exit(84);
        buff[my_strlen(buff) - 1] = '\0';
        minishell(buff, env);
        my_term();
        free(buff);
    }
    return (0);
}