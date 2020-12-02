/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tools_open
*/

#include "tetris.h"

int my_stat(char const *file)
{
    struct stat *buf = malloc(sizeof(struct stat));
    int size = 0;

    stat(file, buf);
    size = buf->st_size;
    free (buf);
    return (size);
}

char *readapting_str(char *str)
{
    if (str[0] == '\0')
        return (str);
    for (int i = 0; str[i] != ' '; i++)
        str[i] = ' ';
    str = my_clean_str(str);
    return (str);
}

int recup_number(char *str)
{
    int nb = 0;
    char *srt_t = NULL;
    int new = 0;

    if (str[0] == '\0')
        return (-1);
    for (; str[nb] != ' ' && str[nb] != '\0'; nb++);
    srt_t = malloc(sizeof(char) * nb + 1);
    if (srt_t == NULL)
        return (-1);
    srt_t[nb] = '\0';
    for (int i = 0; str[i] != ' ' && str[i] != '\0'; i++)
        srt_t[i] = str[i];
    new = my_getnbr(srt_t);
    return (new);
}

char *recup_teris(char *str)
{
    int nb = 0;
    char *new = NULL;

    if (str == NULL)
        return (NULL);
    for (; str[nb] != '\n'; nb++);
    new = malloc(sizeof(char) * (my_strlen(str) - nb) + 1);
    nb++;
    if (new == NULL)
        return (NULL);
    new[(my_strlen(str) - nb)] = '\0';
    for (int i = 0; str[nb] != '\0'; i++, nb++)
        new[i] = str[nb];
    return (new);
}

char *recup_line_info(char *str)
{
    int nb = 0;
    char *new = NULL;

    if (str == NULL)
        return (NULL);
    for (; str[nb] != '\n'; nb++);
    new = malloc(sizeof(char) * nb + 1);
    if (new == NULL)
        return (NULL);
    new[nb] = '\0';
    for (int i = 0; str[i] != '\n'; i++)
        new[i] = str[i];
    return (new);
}