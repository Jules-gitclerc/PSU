/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** tools_var
*/

#include "my.h"
#include "mysh.h"

char *clean_quote(char *str)
{
    char *tmp = malloc(sizeof(char) * my_strlen(str) + 1);
    int x = 0;

    if (tmp == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++, x++) {
        if (str[i] == '"' && str[i + 1] != '\0' && str[i - 1] != 92)
            i++;
        else if (str[i + 1] == '\0' && str[i] == '"' && str[i - 1] != 92)
            break;
        tmp[x] = str[i];
    }
    tmp[x] = '\0';
    return (tmp);
}

char *clean_space(char *str)
{
    char *tmp = malloc(sizeof(char) * my_strlen(str));
    int x = 0;

    if (tmp == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++, x++) {
        if (str[i] == ' ' && str[i + 1] != '\0')
            i++;
        else if (str[i + 1] == '\0' && str[i] == ' ')
            break;
        tmp[x] = str[i];
    }
    tmp[x] = '\0';
    free(str);
    return (tmp);
}

char *replace_space(char *str, int nb)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '=') {
            if (nb == 0)
                str[i] = '$';
            else if (nb == 1)
                str[i] = '=';
            else if (nb == 2)
                str[i] = ' ';
        }
    }
    return (str);
}

char *clean_double(char *str)
{
    char *tmp = malloc(sizeof(char) * my_strlen(str) + 1);
    int x = 0;

    if (tmp == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++, x++) {
        if (str[i] == '$' && str[i + 1] == '$')
            i++;
        tmp[x] = str[i];
    }
    tmp[x] = '\0';
    free(str);
    return (tmp);
}

int count_space2(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            nb++;
    }
    return (nb);
}