/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** check_error
*/

#include "navy.h"

#define enter input[0]

int check_input(char *input)
{
    int nb = 0;

    if (my_strlen(input) != 2) {
        my_printf("wrong position");
        return (84);
    }
    if (!(enter == 'A' || enter == 'B' || enter == 'C' || enter == 'D' ||
        enter == 'E' || enter == 'F' || enter == 'G' || enter == 'H')) {
        my_printf("wrong position");
        return (84);
    }
    nb = input[1] - 48;
    if (nb > 8 || nb < 1) {
        my_printf("wrong position");
        return (84);
    }
    return (0);
}

int count_line(char **file)
{
    int x = 0;

    for (; file[x] != NULL; x++);
    return (x);
}

int check_number(char **file, s_check *check_struct)
{
    int x = -1;

    check_struct->tmp = malloc(sizeof(char) * count_line(file) + 1);
    if (check_struct->tmp == NULL)
        return (-1);
    while (++x < count_line(file))
        check_struct->tmp[x] = file[x][0];
    check_struct->tmp[x] = '\0';
    for (int i = 0; check_struct->tmp[i]; i++) {
        if (!(check_struct->tmp[i] > '1' && check_struct->tmp[i] <= '5'))
            return (-1);
        for (int u = i + 1; check_struct->tmp[u]; u++) {
            if (check_struct->tmp[i] == check_struct->tmp[u])
                return (-1);
        }
    }
    check_struct->tmp[x] = '\0';
    return (0);
}

int check_coor(char **file)
{
    char *str = malloc(sizeof(char) * 2 + 1);
    char *src = malloc(sizeof(char) * 2 + 1);
    int i = -1;
    int x = 0;

    while (++i < count_line(file)) {
        x = -1;
        while (file[i][++x] != ':');
        x += 1;
        for (int u = 0; file[i][x] != ':'; u++, x++)
            str[u] = file[i][x];
        x += 1;
        for (int z = 0; file[i][x]; z++, x++)
            src[z] = file[i][x];
        if (my_strcmp(str, src) == 0 || !(str[1] >= '1' && str[1] <= '8') ||
        !(src[1] >= '1' && src[1] <= '8'))
            return (-1);
    }
    return (0);
}

int check_file(char **file)
{
    s_check check_struct;
    int i = -1;

    while (++i < count_line(file)) {
        if (!(my_strlen(file[i]) == 7))
            return (-1);
        else if (file[i][1] != ':' || file[i][4] != ':')
            return (-1);
    }
    if (check_number(file, &check_struct) == -1 || check_coor(file) == -1 ||
        check_value(file, &check_struct) == -1)
        return (-1);
    return (0);
}
