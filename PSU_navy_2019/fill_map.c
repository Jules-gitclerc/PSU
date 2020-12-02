/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** fill_map
*/

#include "navy.h"

int recup_line(char *str)
{
    int i1 = str[3] - 48;
    int i2 = str[6] - 48;

    if (i1 > i2)
        return (i2);
    else
        return (i1);
}

int check_x_or_y(char *str)
{
    if (str[2] == str[5])
        return (2);
    else
        return (1);
}

int recup_col(char *str)
{
    int i1 = str[2] - 65;
    int i2 = str[5] - 65;

    if (i1 > i2)
        return (i2);
    else
        return (i1);
}

char **fill_info_in_map_bis(char *info, char **map)
{
    int nb = info[0] - 48;
    int loc = check_x_or_y(info);
    int line = recup_line(info) - 1;
    int col = recup_col(info);

    for (int o = 0; o < nb; o++) {
        if (loc == 2) {
            map[line][col] = info[0];
            line++;
        } else if (loc == 1) {
            map[line][col] = info[0];
            col++;
        }
    }
    return (map);
}

char **fill_info_in_map(char *filepath, char **map)
{
    char **info = recup_info_file(filepath);

    if (info[0] == NULL || info == NULL)
        return (NULL);
    if (check_file(info) == -1)
        return (NULL);
    for (int i = 0; info[i] != NULL; i++)
        map = fill_info_in_map_bis(info[i], map);
    for (int i = 0; info[i] != NULL; i++)
        free (info[i]);
    return (map);
}
