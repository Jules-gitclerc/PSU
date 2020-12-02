/*
** EPITECH PROJECT, 2020
** CPE_getnextline_2019
** File description:
** get_next_line
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *my_realloc_tmp(char *str)
{
    int tmp = 0;
    int i = 0;
    char *new = NULL;

    for (; str[tmp] != '\n' && str[tmp] != '\0'; tmp++);
    tmp++;
    if (str[tmp] == '\0')
        return (NULL);
    new = malloc(sizeof(char) * READ_SIZE - tmp + 1);
    for (; tmp < READ_SIZE && str[tmp] != '\0'; i++, tmp++)
        new[i] = str[tmp];
    new[i] = '\0';
    free (str);
    return (new);
}

char *my_realloc(char *str, int nb)
{
    char *new = malloc(sizeof(char) * nb + 1);

    if (new == NULL)
        return (NULL);
    new[nb] = '\0';
    for (int i = 0; i < nb; i++)
        new[i] = str[i];
    free (str);
    return (new);
}

char *my_strdup_case(char *str, int nb)
{
    char *new = malloc(sizeof(char) * nb + READ_SIZE + 1);

    if (new == NULL)
        return (NULL);
    new[nb + READ_SIZE] = '\0';
    for (int i = 0; i < nb; i++)
        new[i] = str[i];
    free (str);
    return (new);
}

char *preparing_buffer(char *buf, int fd)
{
    int read_c = 0;

    if (buf == NULL) {
        buf = malloc(sizeof(char) * READ_SIZE + 1);
        if (buf == NULL)
            return (NULL);
        read_c = read(fd, buf, READ_SIZE);
        if (read_c == 0)
            return (NULL);
        buf[read_c] = '\0';
        return (buf);
    }
    return (buf);
}

char *get_next_line(int fd)
{
    static char *buf = NULL;
    char *str = malloc(sizeof(char) * READ_SIZE + 1);
    int nb = 0;

    buf = preparing_buffer(buf, fd);
    if (str == NULL || buf == NULL)
        return (NULL);
    for (int i = 0; buf[i] != '\n'; i++, nb++) {
        if (buf[i] == '\0') {
            free(buf);
            buf = NULL;
            buf = preparing_buffer(buf, fd);
            if (buf == NULL)
                return (my_realloc(str, nb));
            str = my_strdup_case(str, nb);
            i = 0;
        }
        str[nb] = buf[i];
    }
    buf = my_realloc_tmp(buf);
    return (my_realloc(str, nb));
}
