/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** check_pos
*/

#include "navy.h"

char *create_str(char **file)
{
    int u = 0;
    int nb = 0;
    char *tmp;

    for (int i = 0; i < count_line(file); i++) {
        for (int x = 0; file[i][x]; x++)
            if (file[i][x] == ':')
                nb++;
    }
    tmp = malloc(sizeof(char) * (nb * 2) + 1);
    if (tmp == NULL)
        return (NULL);
    for (int y = 0; y < count_line(file); y++) {
        for (int x = 2; file[y][x]; x++, u++) {
            if (file[y][x] == ':')
                x += 1;
            tmp[u] = file[y][x];
        }
    }
    tmp[u] = '\0';
    return (tmp);
}

int check_c(char *str, s_check *check_struct)
{
    int i = 0;
    int c = 0;
    char *src = malloc(sizeof(char) * 2);
    char *dest = malloc(sizeof(char) * 2);

    while (str[i]) {
        for (int n = 0; n < 2; n++, i++)
            src[n] = str[i];
        for (int u = 0; u < 2; u++, i++)
            dest[u] = str[i];
        if ((check_struct->tmp[c] - '0') != (dest[0] - src[0]) + 1 &&
        (check_struct->tmp[c] - '0') != (dest[1] - src[1]) + 1)
            return (-1);
        c++;
    }
    return (0);
    free(src);
    free(dest);
    free(check_struct->tmp);
}

int check_value(char **file, s_check *check_struct)
{
    char *src = malloc(sizeof(char) * 2 + 1);
    char *dest = malloc(sizeof(char) * 2 + 1);
    int x = 0;
    int u = 0;
    char *str;

    if ((str = create_str(file)) == NULL || check_c(str, check_struct) == -1)
        return (-1);
    for (int i = 0; str[i]; i += 2) {
        x = i;
        for (int n = 0; n < 2; n++, x++)
            src[n] = str[x];
        u = x;
        while (u != my_strlen(str)) {
            for (int n = 0; n < 2; n++, u++)
                dest[n] = str[u];
            if (my_strcmp(src, dest) == 0)
                return (-1);
        }
    }
    return (0);
}