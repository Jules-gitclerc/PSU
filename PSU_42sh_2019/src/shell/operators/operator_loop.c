/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** operator_loop
*/

#include "mysh.h"

int is_evaluated(int val, char *ops, int i, int is_or)
{
    if (i == 0)
        return (1);
    if (is_or == 1)
        return (0);
    if (ops[i] == '&' && ((val != 0 && val != 1) || val == -1))
        return (0);
    if (ops[i] == '&' && (val == 0 || val == 1))
        return (1);
    if (ops[i] == '|' && val == -1 && ops[i - 1] == '&')
        return (1);
    if (ops[i] == '|' && val == -1 && ops[i - 1] == '|')
        return (0);
    if (ops[i] == '|' && (val == 0 || val == 1))
        return (0);
    return (1);
}

int launch_cmd(env_t *env, char *cmd, shell_t *shell)
{
    char *command = NULL;
    char **pipe_sep = NULL;
    int ret_val = 0;

    command = my_clean_str(cmd);
    pipe_sep = my_str_to_word_array(command, '|');
    if (check_error_command(command) != 84)
        ret_val = pipe_proc(pipe_sep, env, shell);
    shell->exit_value = ret_val;
    free (command);
    free_double_tab(pipe_sep);
    return (ret_val);
}

int operator_loop(env_t *env, char *input, shell_t *shell)
{
    char **cmd_tab = ft_split_2_sep(input, "&&", "||");
    char *op_tab = get_operators(input);
    int ret_val = 0;
    int is_or = 0;

    if (cmd_tab == NULL || op_tab == NULL)
        return (84);
    for (int i = 0; cmd_tab[i] != NULL; i++) {
        if (cmd_tab[i][0] != '\0' && \
            is_evaluated(ret_val, op_tab, i, is_or) == 1)
            ret_val = launch_cmd(env, cmd_tab[i], shell);
        else
            ret_val = -1;
        if (ret_val == 0 && op_tab[i + 1] == '|')
            is_or = 1;
    }
    free_double_tab(cmd_tab);
    return (0);
}