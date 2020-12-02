/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** recup_input
*/

#include "navy.h"

char *my_realloc_read(char *buf, char letter)
{
    int nb = my_strlen(buf) + 1;
    char *new = malloc(sizeof(char) * nb + 1);
    int i = 0;

    if (new == NULL)
        return (NULL);
    new[nb] = '\0';
    for (; buf[i] != '\0'; i++)
        new[i] = buf[i];
    new[i] = letter;
    free (buf);
    return (new);
}

int take_imput_line(struct playeur_one *p_o)
{
    char letter;
    int read_c;

    p_o->input = malloc(sizeof(char));
    my_printf("\nattack: ");
    p_o->input[0] = '\0';
    for (letter = '\0'; letter != '\n'; letter = letter) {
        read_c = read(0, &letter, 1);
        if (letter == '\n')
            break;
        if (read_c <= 0)
            return (-1);
        p_o->input = my_realloc_read(p_o->input, letter);
    }
    p_o->input = my_clean_str(p_o->input);
    if (check_input(p_o->input) == 84)
        return (take_imput_line(p_o));
    return (0);
}