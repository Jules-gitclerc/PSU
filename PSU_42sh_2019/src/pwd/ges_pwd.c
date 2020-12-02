/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** ges_pwd
*/

#include "mysh.h"

char *recup_pwd(void)
{
    char cwd[256];
    int i = 0;
    char *str = NULL;

    getcwd(cwd, sizeof(cwd));
    str = malloc(sizeof(char) * my_strlen(cwd) + 1);
    if (str == NULL)
        return (NULL);
    for (; cwd[i] != '\0'; i++)
        str[i] = cwd[i];
    str[i] = '\0';
    return (str);
}
