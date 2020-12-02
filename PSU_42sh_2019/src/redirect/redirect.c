/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** tools_redirect
*/

#include "mysh.h"

char *recup_com_redirect(char *input)
{
    char *new = NULL;
    int nb_carat = 0;

    for (; input[nb_carat] != '\0' && input[nb_carat] != '>'; nb_carat++);
    new = malloc(sizeof(char) * (nb_carat + 1));
    if (new == NULL)
        return (NULL);
    new[nb_carat] = '\0';
    for (int i = 0; input[i] != '\0' && input[i] != '>'; i++)
        new[i] = input[i];
    return (new);
}

char *recup_path_redirect(char *input)
{
    int nb_carat = 0;
    int t_carat = 0;
    char *new = NULL;

    for (; input[nb_carat] != '\0' && input[nb_carat] != '>'; nb_carat++);
    if (input[nb_carat + 1] != '\0' && input[nb_carat + 1] == '>')
        nb_carat++;
    nb_carat++;
    t_carat = my_strlen(input) - nb_carat;
    new = malloc(sizeof(char) * (t_carat + 1));
    if (new == NULL)
        return (NULL);
    new[t_carat] = '\0';
    for (int i = 0; input[nb_carat] != '\0'; nb_carat++, i++)
        new[i] = input[nb_carat];
    return (new);
}

int s_rect_left(char *path)
{
    int fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0664);

    free (path);
    if (fd == -1)
        return (-1);
    return (fd);
}

int d_rect_left(char *path)
{
    int fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0664);

    free (path);
    if (fd == -1)
        return (-1);
    return (fd);
}

int ges_left_redirect(char *input)
{
    char *tab_l_red[3] = {">>", ">", 0};
    int (*fct[2]) (char *path) = {d_rect_left, s_rect_left};

    for (int i = 0; tab_l_red[i] != 0; i++) {
        if (my_strcmp_carat(tab_l_red[i], input) == 1)
            return (fct[i](my_clean_str(recup_path_redirect(input))));
    }
    return (-1);
}
