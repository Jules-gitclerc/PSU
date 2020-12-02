/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_echo
*/

#include "mysh.h"

void print_exit_value(char **com, shell_t *shell)
{
    (void)com;
    my_printf("%i\n", shell->exit_value);
    shell->exit_value = 0;
}

void flag_n_echo(char **com, shell_t *shell)
{
    (void)shell;
    for (int i = 2; com[i] != NULL; i++) {
        if (i != 2)
            my_printf(" ");
        my_printf("%s", com[i]);
    }
    free_double_tab(com);
}

void simple_echo(char **com)
{
    for (int i = 1; com[i] != NULL; i++) {
        if (i != 1)
            my_printf(" ");
        my_printf("%s", com[i]);
    }
    my_printf("\n");
}

char *clean_backslash(char *str)
{
    char *tmp = malloc(sizeof(char) * my_strlen(str) + 1);
    int x = 0;

    if (tmp == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++, x++) {
        if (str[i] == 92 && str[i + 1] != '\0')
            i++;
        else if (str[i + 1] == '\0' && str[i] == 92)
            break;
        tmp[x] = str[i];
    }
    tmp[x] = '\0';
    return (tmp);
}

void my_echo(env_t *env, char *input, shell_t *shell)
{
    char **com = my_str_to_word_array(clean_quote(input), ' ');
    char *flag[3] = {"-n", "$?", 0};
    int i = 0;
    void (*fct[2])(char **com, shell_t *shell) = {flag_n_echo, \
        print_exit_value};

    (void)env;
    if (com[1] == NULL) {
        my_printf("\n");
        free_double_tab(com);
        return;
    }
    com[1] = clean_backslash(com[1]);
    for (; flag[i] != 0; i++)
        if (my_strcmp(flag[i], com[1]) == 0) {
            fct[i](com, shell);
            return;
        }
    if (flag[i] == 0)
        simple_echo(com);
    free_double_tab(com);
}