/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** utils_str
*/

#include "my.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

char *my_custom_strcat(char *path, char *command, int cond)
{
    char *tab;
    int	i = -1;
    int	j = 0;

    if (path == NULL || command == NULL)
        return (NULL);
    if ((tab = malloc(sizeof(char) * (my_strlen(path) +
            my_strlen(command) + 2))) == NULL)
        return (NULL);
    while (path[++i] != '\0')
        tab[i] = path[i];
    if (cond == 1)
        tab[i++] = '/';
    if (cond == 2)
        tab[i++] = '=';
    while (command[j] != '\0')
        tab[i++] = command[j++];
    tab[i] = '\0';
    return (tab);
}

int	my_count(char *str, char c)
{
    int		i = 0;
    int		count = 0;

    while (str[i] != '\0') {
        while (str[i] && (str[i] == c || str[i] == '\t'))
            i++;
        if (str[i])
            count++;
        if (str[i] != '\0')
            i++;
    }
    return (count);
}

int	my_tab(char *str, char c)
{
    int		i = -1;

    while (str[++i] != '\0' && str[i] != c && str[i] != '\t');
    return (i);
}

char **my_str_custom_array(char *str, char c)
{
    char **tab = malloc((my_count(str, c) + 1) * sizeof(*tab));
    int i = 0;
    int z = -1;
    int j;

    if (tab == NULL)
        return (NULL);
    while (str[i]) {
        j = 0;
        while (str[i] && (str[i] == c || str[i] == ' ' || str[i] == '\t'))
            ++i;
        if ((tab[++z] = malloc((my_tab(&str[i], c) + 1) *
            sizeof(**tab))) == NULL)
            return (NULL);
        while (str[i] && str[i] != c && str[i] != ' ' && str[i] != '\t')
            tab[z][j++] = str[i++];
        tab[z][j] = '\0';
        while (str[i] && (str[i] == c || str[i] == ' ' || str[i] == '\t'))
            ++i;
    }
    tab[z + 1] = '\0';
    return (tab);
}

char my_custom_strcmp(char *s1, char *s2)
{
  int		i = -1;
  
  while (s1[++i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]);
  return ((s1[i] == s2[i] || s1[i] == ' ' || s1[i] == '\t') && s2[i] == '\0');
}