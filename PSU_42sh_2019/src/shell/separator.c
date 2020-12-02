/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** separator
*/

#include "mysh.h"

int my_strcmp_carat(char *red, char *input)
{
    int nb = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        for (int tmp = i; input[tmp] == red[nb] && \
        input[tmp] != '\0' && red[nb] != '\0'; tmp++)
            nb++;
        if (nb == my_strlen(red))
            return (1);
        nb = 0;
    }
    return (0);
}

int check_redir_left(char *input)
{
    char *redir[3] = {"<<", "<", 0};
    int ret[3] = {2, 1, 0};

    for (int i = 0; redir[i] != 0; i++)
        if (my_strcmp_carat(redir[i], input) == 1)
            return (ret[i]);
    return (0);
}

int looking_input(env_t *env, char *input, shell_t *shell)
{
    int len = 0;
    int status = 0;
    int mode = 0;
    char **com = my_str_to_word_array(input, '<');

    for (alias_t *cur = shell->alias->next; cur != NULL; cur = cur->next, len++);
    for (int i = 0; i <= len; i++)
        input = check_alias(input, shell->alias);
    mode = check_redir_left(input);
    if (mode == 1) {
        redir_left(input, shell);
        status = my_exe(env, my_clean_str(com[0]));
        reset_fd(shell);
    } else if (mode == 2) {
        double_redir_left(input, shell);
        status = display_reset_save(shell->save, input, env);
    } else
        status = my_exe(env, input);
    free_double_tab(com);
    return (status);
}

void separator(env_t *env, char *input, shell_t *shell)
{
    char **sep = my_str_to_word_array(input, ';');
    char *command = NULL;
    char *load = NULL;

    for (int i = 0; sep[i] != NULL; i++) {
        load = my_clean_str(sep[i]);
        if (sep[i][0] != '\0' && load != NULL) {
            command = my_clean_str(sep[i]);
            if (check_op_errors(command) != 84)
                operator_loop(env, command, shell);
            free (command);
        }
    }
    free_double_tab(sep);
}
