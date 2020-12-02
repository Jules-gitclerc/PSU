/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** tools_pipe
*/

#include "mysh.h"

int count_nb_pipe(char *command)
{
    int count = 0;

    for (int i = 0; command[i] != '\0'; i++)
        if (command[i] == '|')
            count++;
    return (count);
}
