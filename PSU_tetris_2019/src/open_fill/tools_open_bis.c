/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tools_open_bis
*/

#include "tetris.h"

int check_tetris(char *str)
{
    int i = 0;

    for (; str[i] != '\n'; i++);
    for (; str[i] != '\0'; i++)
        if (str[i] != '*' && str[i] != '\n' && str[i] != ' ')
            return (-1);
    return (0);
}

void check_end_line(trimino_d *cur)
{
    int nb_coma = 0;

    for (int i = 0; cur->triminos[i] != NULL; i++) {
        for (int o = 0; cur->triminos[i][o] != '\0'; o++)
            if (cur->triminos[i][o] == '*')
                nb_coma += 1;
        if (nb_coma == 0) {
            free (cur->triminos[i]);
            cur->triminos[i] = NULL;
        } else
            nb_coma = 0;
    }
}

void check_end_tab(trimino_d *mino)
{
    for (trimino_d *cur = mino->next; cur != NULL; cur = cur->next)
        if (cur->error != 1)
            check_end_line(cur);
}

int check_well_name(char *name)
{
    int nb_p = 0;

    if (name[0] == '\0' || name[0] == '.')
        return (-1);
    for (int i = 0; name[i] != '\0'; i++)
        if (name[i] == '.')
            nb_p += 1;
    if (nb_p == 0)
        return (-1);
    return (0);
}

char *take_name(char *b_name)
{
    int nb = 0;
    char *new = NULL;

    if (check_well_name(b_name) == -1)
        return ("Error");
    for (; b_name[nb] != '.'; nb++);
    new = malloc(sizeof(char) * nb + 1);
    if (new == NULL)
        return (NULL);
    new[nb] = '\0';
    for (int i = 0; b_name[i] != '.'; i++)
        new[i] = b_name[i];
    return (new);
}
