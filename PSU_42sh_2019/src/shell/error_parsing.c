/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** error_parsing
*/

#include "mysh.h"

char *my_strdup_line(char *str)
{
    int nb = my_strlen(str);
    char *new = malloc(sizeof(char) * (nb + 1));

    if (new == NULL)
        return (NULL);
    new[nb] = '\0';
    for (int i = 0; i < nb; i++)
        new[i] = str[i];
    return (new);
}

int count_nb_tab_symbole(char **map)
{
    int count = 0;

    for (int i = 0; map[i] != NULL; i++)
        if (map[i][0] == '|' || map[i][0] == '>' || map[i][0] == '<')
            count++;
    return (count);
}

char **recup_symbole_tab(char *input)
{
    char **pars_com = my_str_to_word_array(input, ' ');
    int size = count_nb_tab_symbole(pars_com);
    char **new = malloc(sizeof(char *) * (size + 1));
    int o = 0;

    if (new == NULL)
        return (NULL);
    new[size] = NULL;
    for (int i = 0; pars_com[i] != NULL; i++) {
        if (pars_com[i][0] == '|' || pars_com[i][0] == '>'
        || pars_com[i][0] == '<') {
            new[o] = my_strdup_line(pars_com[i]);
            o++;
        }
    }
    free_double_tab(pars_com);
    return (new);
}

int check_bad_redirect(char *input)
{
    int i = 0;
    char **symb = recup_symbole_tab(input);

    for (; symb[i] != NULL && symb[i][0] != '>'; i++);
    if (symb[i] != NULL)
        for (; symb[i] != NULL; i++)
            if (symb[i][0] == '|') {
                my_printf("Ambiguous output redirect.\n");
                return (84);
            }
    free_double_tab(symb);
    if (input[0] == '|' || input[my_strlen(input) - 1] == '|') {
        my_printf("%s\n", "Invalid null command.");
        return (84);
    }
    return (0);
}

int check_error_command(char *input)
{
    char *tab_error[18] = {"| |", "<< <<", ">> >>", "> >", "< <", "< >", \
    "<< >>", "<>", "><", ">> <<", "<< >>", "> <", "< >", "| >", "| >>", \
    "| <", "| <<", 0};
    char *print_error[3] = {"Invalid null command.",
                    "Missing name for redirect.", 0};
    int run = 0;

    if (check_bad_redirect(input) == 84)
        return (84);
    for (int i = 0; tab_error[i] != 0; i++) {
        if (my_strcmp_carat(tab_error[i], input) == 1) {
            my_printf("%s\n", print_error[run], i);
            return (84);
        }
        if (i == 0)
            run += 1;
    }
    return (0);
}
