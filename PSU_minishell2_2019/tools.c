/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** tools_str
*/

#include <stdio.h>
#include "mysh.h"
#include <stdlib.h>
#include <unistd.h>

void my_free(char **tab)
{

    if (tab != NULL) {
        for (int i = 0; tab[i] != NULL; i++)
            free(tab[i]);
        free(tab);
    }
}