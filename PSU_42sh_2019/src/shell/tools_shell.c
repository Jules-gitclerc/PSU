/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** tools_shell
*/

#include "mysh.h"

char *recup_first_command(char *input)
{
    int nb = 0;
    char *new = NULL;

    for (nb = 0; input[nb] != ' ' && input[nb] != '\0'; nb++);
    new = malloc(sizeof(char) * nb + 1);
    if (new == NULL)
        return (NULL);
    new[nb] = '\0';
    for (int i = 0; input[i] != ' ' && input[i] != '\0'; i++)
        new[i] = input[i];
    return (new);
}

void free_double_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free (tab[i]);
    free (tab);
}
