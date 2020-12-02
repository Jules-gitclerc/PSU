/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** fct_flag_pause.c
*/

#include "tetris.h"

int recup_second_number(char *str)
{
    int nb = 0;
    int run = 0;
    char *new = NULL;

    for (; str[run] != ','; run++);
    run++;
    for (int i = run; str[i] != '\0'; i++, nb++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (-1);
    if (nb == 0)
        return (-1);
    new = malloc(sizeof(char) * nb + 1);
    new[nb] = '\0';
    for (int i = 0; i < nb; i++, run++)
        new[i] = str[run];
    return (my_getnbr(new));
}

int recup_first_number(char *str)
{
    int nb_stroph = 0;
    int nb = 0;
    char *new = NULL;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ',')
            nb_stroph += 1;
    if (nb_stroph != 1)
        return (-1);
    for (int i = 0; str[i] != ','; i++, nb++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (-1);
    if (nb == 0)
        return (-1);
    new = malloc(sizeof(char) * nb + 1);
    new[nb] = '\0';
    for (int i = 0; i < nb; i++)
        new[i] = str[i];
    return (my_getnbr(new));
}

int conf_map_size(key_p *key, char *str)
{
    int line = recup_first_number(str);
    int colum = 1;

    if (line <= 0) {
        my_printf("Bad input for map size\n");
        exit (84);
    }
    colum = recup_second_number(str);
    if (colum <= 0) {
        my_printf("Bad input for map size\n");
        exit (84);
    }
    key->line = line;
    key->colum = colum;
    return (0);
}

int recup_level_number(char *str)
{
    int nb = 0;
    char *new = NULL;

    for (int i = 0; str[i] != '\0'; i++, nb++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (-1);
    if (nb == 0)
        return (-1);
    new = malloc(sizeof(char) * nb + 1);
    new[nb] = '\0';
    for (int i = 0; i < nb; i++)
        new[i] = str[i];
    return (my_getnbr(new));
}

int conf_level(key_p *key, char *str)
{
    int level = recup_level_number(str);

    if (level <= 0) {
        my_printf("Error for change level, please check --help\n");
        exit (84);
    } else
        key->level = level;
    return (0);
}
