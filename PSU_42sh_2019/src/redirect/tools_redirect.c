/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** tools_redirect
*/

#include "mysh.h"

int display_reset_save(save_t *save, char *input, env_t *env)
{
    char **com = my_str_to_word_array(input, '<');
    save_t *cur = save->next;
    int status = 0;

    if (my_strcmp("cat", my_clean_str(com[0])) == 0) {
        for (; cur != NULL; cur = cur->next)
            my_printf("%s\n", cur->line);
        exit (0);
    } else if (my_strcmp("cat",
        my_clean_str(recup_first_command(input))) == 0) {
        status = my_exe(env, my_clean_str(com[0]));
        for (; cur != NULL; cur = cur->next)
            my_printf("%s\n", cur->line);
    } else
        status = my_exe(env, my_clean_str(com[0]));
    save->next = NULL;
    return (status);
}

int add_node_save(save_t *save, char *input)
{
    save_t *cur = save;

    for (; cur->next != NULL; cur = cur->next);
    cur->next = malloc(sizeof(save_t));
    if (cur->next == NULL)
        return (84);
    cur = cur->next;
    cur->next = NULL;
    cur->line = my_strdup_name(input);
    return (0);
}