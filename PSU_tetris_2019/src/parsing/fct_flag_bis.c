/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** fct_flag_bis.c
*/

#include "tetris.h"

int key_pause(key_p *key, char *str)
{
    int new_key = recup_char_key(str);

    if (new_key == -1) {
        my_printf("Bad input for key pause\n");
        exit (84);
    } else
        key->pause = new_key;
    return (0);
}

int recup_char_key(char *str)
{
    if (str == NULL)
        return (-1);
    if (my_strlen(str) != 1)
        return (-1);
    return (str[0]);
}

char *recup_key(char *str)
{
    int i = 0;
    char *key = NULL;
    int nb_l_key = 0;

    for (; str[i] != '='; i++);
    i++;
    for (int o = i; str[o] != '\0'; o++, nb_l_key++);
    key = malloc(sizeof(char) * nb_l_key + 1);
    if (key == NULL)
        return (NULL);
    key[nb_l_key] = '\0';
    for (int index = 0; index < nb_l_key && str[i] != '\0'; index++, i++)
        key[index] = str[i];
    return (key);
}

void init_classic_key(key_p *key)
{
    key->quit = 'q';
    key->pause = ' ';
    key->left = 4;
    key->right = 3;
    key->turn = 1;
    key->drop = 2;
    key->level = 1;
    key->line = 20;
    key->colum = 10;
    key->next = 0;
    key->i = 0;
    key->r = 0;
}
