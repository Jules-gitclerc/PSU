/*
** EPITECH PROJECT, 2019
** my_lib_C
** File description:
** my_str_to_word_array.c
*/

#include <unistd.h>
#include <stdlib.h>

char **my_str_to_word_array_bis(char *str, char **new, int nb, char letter)
{
    int y = 0;
    int run = 0;
    int tmp = 0;

    new = malloc(sizeof(char *) * (nb + 1));
    if (new == NULL)
        return (NULL);
    new[nb] = NULL;
    for (int i = 0; i < nb; i++, run++) {
        tmp = run;
        for (y = 0; str[run] != letter && str[run] != '\0'; run++, y++);
        new[i] = malloc(sizeof(char) * (y + 1));
        if (new[i] == NULL)
            return (NULL);
        new[i][y] = '\0';
        run = tmp;
        for (int o = 0; str[run] != letter && str[run] != '\0'; o++, run++)
            new[i][o] = str[run];
    }
    return (new);
}

char **my_str_to_word_array(char *str, char letter)
{
    int nb = 1;
    char **new = NULL;

    if (str[0] == '\0')
        return (new);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == letter)
            nb++;
    new = my_str_to_word_array_bis(str, new, nb, letter);
    return (new);
}
