/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** my_exit
*/

#include "mysh.h"

void my_exit(env_t *env, char *input, shell_t *shell)
{
    unsigned int quit = 0;
    char **com = my_str_to_word_array(input, ' ');

    (void)shell;
    if (com[1] == NULL) {
        if (isatty(0) == 1)
            my_printf("exit\n");
        exit (0);
    }
    for (int i = 0; com[1][i] != '\0'; i++)
        if (!(com[1][i] >= '0' && com[1][i] <= '9')) {
            my_printf("exit: Expression Syntax.\n");
            return;
        }
    if (isatty(0) == 1)
        my_printf("exit\n");
    quit = my_getnbr(com[1]);
    free_double_tab(com);
    destroy_env_list(env);
    exit(quit);
}
