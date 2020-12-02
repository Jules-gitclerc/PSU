/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** ges_alais
*/

#include "mysh.h"

char *my_strdup_name(char *str)
{
    int nb = my_strlen(str);
    char *new = malloc(sizeof(char) * (nb + 1));

    if (new == NULL)
        return (new);
    new[nb] = '\0';
    for (int i = 0; str[i] != '\0'; i++)
        new[i] = str[i];
    return (new);
}

char *concat_command_alias(char *input)
{
    char *new = NULL;
    int i = 0;

    for (int x = 0; x != 2; i++)
        if (input[i] == ' ')
            x += 1;
        else
            input[i] = ' ';
    new = my_clean_str(input);
    return (new);
}

int add_in_node_alias(alias_t *alias, char *name, char *command)
{
    alias_t *cur = alias;

    for (; cur->next != NULL; cur = cur->next);
    cur->next = malloc(sizeof(alias_t));
    if (cur->next == NULL)
        return (84);
    cur = cur->next;
    cur->next = NULL;
    cur->command = my_strdup_name(command);
    cur->name = my_strdup_name(name);
    free (command);
    return (0);
}

void mana_alias_many_arg(shell_t *shell, char **com, char *input)
{
    alias_t *cur = shell->alias->next;

    for (; cur != NULL; cur = cur->next)
        if (my_strcmp(com[1], cur->name) == 0) {
            free (cur->command);
            cur->command = my_strdup_name(concat_command_alias(input));
            return;
        }
    add_in_node_alias(shell->alias, com[1], concat_command_alias(input));
}

void my_alias(env_t *env, char *input, shell_t *shell)
{
    char **com = my_str_to_word_array(input, ' ');
    int count = 0;

    (void)env;
    for (; com[count] != NULL; count++);
    if (count == 1)
        display_alias(shell->alias);
    else if (count == 2)
        look_and_display(shell->alias, com[1]);
    else
        mana_alias_many_arg(shell, com, input);
    free_double_tab(com);
}