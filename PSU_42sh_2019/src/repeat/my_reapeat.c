/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_reapeat
*/

#include "mysh.h"

char *concat_command(char *input)
{
    int len = 0;

    for (int i = 0; input[i] != '\0' && len < 2; i++) {
        if (input[i] == ' ')
            len += 1;
        input[i] = ' ';
    }
    return (my_clean_str(input));
}

void my_repeat(env_t *env, char *input, shell_t *shell)
{
    char **com = my_str_to_word_array(input, ' ');
    int loop = 0;
    char *commnd = NULL;

    if (com[1] == NULL || com[2] == NULL) {
        my_printf("repeat: Too few arguments.\n");
        return;
    } if (my_str_isnum(com[1]) == 0) {
        my_printf("repeat: Badly formed number.\n");
        return;
    }
    commnd = concat_command(my_strdup_name(input));
    loop = my_getnbr(com[1]);
    for (int i = 0; i <= loop; i++)
        pipe_proc(my_str_to_word_array(commnd, '|'), env, shell);
    free_double_tab(com);
}