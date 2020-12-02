/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** shell
*/

#include "mysh.h"

void init_struct_shell(shell_t *shell, char *pwd)
{
    go_to_racine(shell, pwd);
    init_alias(shell);
    init_var(shell);
    shell->save = malloc(sizeof(save_t));
    shell->save->line = NULL;
    shell->save->next = NULL;
    shell->exit_value = 0;
    free (pwd);
}

int pars_command(env_t *env, char *input, shell_t *shell, int mode)
{
    char *tab[14] = {"env", "exit", "setenv", "unsetenv", "cd", "alias", \
                    "echo", "unalias", "where", "which", "repeat", "set", \
                    "unset", 0};
    void (*fct[13]) (env_t *env, char *input, shell_t *shell) = {my_env, \
        my_exit, my_setenv, my_unsetenv, my_cd, my_alias, my_echo, \
        my_unalias, my_where, my_which, my_repeat, my_set, my_unset_var};
    char *first_command = recup_first_command(input);
    int indic[13] = {0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1};

    for (int i = 0; tab[i] != 0; i++) {
        if (my_strcmp(tab[i], first_command) == 0) {
            if (indic[i] == 0 && mode != 1)
                return (0);
            fct[i](env, input, shell);
            free (first_command);
            return (1);
        }
    }
    return (0);
}

void loop_shell(env_t *env)
{
    char *input = NULL;
    shell_t shell;
    signal(SIGINT, signal_ctrl_c);

    init_struct_shell(&shell, recup_pwd());
    while (1) {
        if (isatty(0) == 1)
            my_printf("\033[34;01m%s$> \033[00m", recup_pwd());
        input = recup_input(env);
        if (input != NULL) {
            input = check_var(input, env, &shell);
            separator(env, input, &shell);
            free (input);
        }
    }
}
