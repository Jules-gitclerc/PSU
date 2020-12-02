/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** ges_input
*/

#include "mysh.h"

char *suppr_one_carat(char *input)
{
    int nb = my_strlen(input) - 1;
    char *new = NULL;

    if (input[0] == '\0')
        return (input);
    new = malloc(sizeof(char) * (nb + 1));
    if (new == NULL)
        return (input);
    new[nb] = '\0';
    for (int i = 0; i < nb; i++)
        new[i] = input[i];
    free(input);
    return (new);
}
