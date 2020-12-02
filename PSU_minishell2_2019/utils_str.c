/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** utils_str
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"

int my_counter(char *str, char c, int k)
{
    int i = 0;
    int count = 0;

    while (str[i]) {
        while (str[i] && (str[i] == c || str[i] == k || str[i] == '\t'))
            i++;
        count += (str[i]) ? (1) : (0);
        i += (str[i]) ? (1) : (0);
    }
    return (count);
}

char *my_custom_strcat(char *path, char *command, int cond)
{
    char *tab;
    int i;
    int j;

    if (path == NULL || command == NULL)
        return (NULL);
    if ((tab = malloc(sizeof(char) * (my_strlen(path) +
        my_strlen(command) + 2))) == NULL)
        exit(84);
    i = -1;
    while (path[++i] != '\0')
        tab[i] = path[i];
    if (cond == 1)
        tab[i++] = '/';
    if (cond == 2)
        tab[i++] = '=';
    j = 0;
    while (command[j] != '\0')
        tab[i++] = command[j++];
    tab[i] = '\0';
    return (tab);
}

static char *return_tab(char *str, int count)
{
    char *tab;
    int i;
    int size = count;

    while (str[size - 1] == ' ' || str[size - 1] == '\t')
        size -= 1;
    tab = malloc(sizeof(char) * size + 1);
    if (tab == NULL)
        return (NULL);
    i = -1;
    while (str[++i] && i < size)
        tab[i] = str[i];
    tab[i] = '\0';
    return (tab);
}

static char *my_str(char *str, int *i, char c, char k)
{
    int size = 0;
    int j = -1;
    int len = 0;

    while (str[++j] == c || str[j] == k)
        len += 1;
    j = 0;
    while (str[j] && ((str[j] != c && str[j] != k))) {
        size += 1;
        j += 1;
        (*i)++;
    }
    while (len-- > 0) {
        (*i)++;
        size += 1;
    }
    (*i)--;
    return (return_tab(str, size));
}

char **separe_wordtab(char *str, char c)
{
    char **tab = malloc((my_counter(str, c, '\0') + 1) * sizeof(*tab));
    int i = 0;
    int z = -1;

    if (tab == NULL)
        exit(84);
    while (str[i]) {
        while (str[i] && (str[i] == c || str[i] == ' ' || str[i] == '\t'))
            i += 1;
        tab[++z] = (str[i]) ? my_str(&str[i], &i, c, 12) : '\0';
        i += (str[i]) ? (1) : (0);
    }
    tab[z + 1] = '\0';
    return (tab);
}