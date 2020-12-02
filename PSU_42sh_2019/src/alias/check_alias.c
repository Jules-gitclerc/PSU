/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** check_alias
*/

#include "mysh.h"

int global;

int count_space(char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            len++;
    return (len);
}

int count_carat_double_tab(char **com)
{
    int nb = 0;

    for (int i = 0; com[i] != NULL; i++) {
        nb += my_strlen(com[i]) + 1;
    }
    nb -= 1;
    return (nb);
}

char *concat_double_tab(char **com)
{
    int nb = count_carat_double_tab(com);
    char *new = malloc(sizeof(char) * (nb + 1));
    int len = 0;

    if (new == NULL)
        exit (84);
    new[nb] = '\0';
    for (int i = 0; com[i] != NULL; len++, i++) {
        for (int x = 0; com[i][x] != '\0' && len < nb; x++, len++)
            new[len] = com[i][x];
        if (com[i + 1] != NULL)
            new[len] = ' ';
    }
    return (new);
}

char *insert_comand(char *input, char *name, char *command)
{
    char **com = my_str_to_word_array(input, ' ');
    int i = global;

    for (; com[i] != NULL; i++)
        if (my_strcmp(name, com[i]) == 0) {
            free (com[i]);
            com[i] = my_strdup_name(command);
            global = i + count_space(com[i]);
        }
    free (input);
    return (concat_double_tab(com));
}

char *check_alias(char *input, alias_t *alias)
{
    char **com = my_str_to_word_array(input, ' ');
    alias_t *cur = alias->next;

    global = 0;
    for (int i = 0; com[i] != NULL; i++) {
        for (cur = alias->next; cur != NULL; cur = cur->next)
            if (my_strcmp(com[i], cur->name) == 0) {
                input = insert_comand(input, cur->name, cur->command);
                break;
            }
    }
    return (input);
}