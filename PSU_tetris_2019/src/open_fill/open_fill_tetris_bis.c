/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** open_fill_tetris_bis.c
*/

#include "tetris.h"

void init_wrong_tetris_node(trimino_d *cur, char *file)
{
    cur->error = 1;
    cur->name = take_name(file);
    cur->color = -1;
    cur->nb_colum = -1;
    cur->nb_line = -1;
    cur->next = NULL;
    cur->triminos = NULL;
}

void fill_node(trimino_d * cur, char *info)
{
    cur->nb_colum = recup_number(info);
    info = readapting_str(info);
    cur->nb_line = recup_number(info);
    info = readapting_str(info);
    cur->color = recup_number(info);
    free (info);
}

void init_well_tetris_mode(trimino_d *cur, char *file, char *str)
{
    char *tetris = recup_teris(str);
    char *info_t = my_clean_str(recup_line_info(str));

    free (str);
    cur->next = NULL;
    cur->triminos = my_str_to_word_array(tetris, '\n');
    cur->name = take_name(file);
    fill_node(cur, info_t);
}

int check_first_line_file(char *str)
{
    int nb_space = 0;

    if (my_strlen(str) < 5)
        return (-1);
    str = my_clean_str(str);
    for (int i = 0; str[i] != '\0'; i++)
        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
            return (-1);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            nb_space += 1;
    if (nb_space != 2)
        return (-1);
    return (0);
}