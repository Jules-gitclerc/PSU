/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** fct_flag.c
*/

#include "tetris.h"

int key_left(key_p *key, char *str)
{
    int new_key = recup_char_key(str);

    if (new_key == -1) {
        my_printf("Bad input for key left\n");
        exit (84);
    } else
        key->left = new_key;
    return (0);
}

int key_right(key_p *key, char *str)
{
    int new_key = recup_char_key(str);

    if (new_key == -1) {
        my_printf("Bad input for key right\n");
        exit (84);
    } else
        key->right = new_key;
    return (0);
}

int key_turn(key_p *key, char *str)
{
    int new_key = recup_char_key(str);

    if (new_key == -1) {
        my_printf("Bad input for key turn\n");
        exit (84);
    } else
        key->turn = new_key;
    return (0);
}

int key_drop(key_p *key, char *str)
{
    int new_key = recup_char_key(str);

    if (new_key == -1) {
        my_printf("Bad input for key drop\n");
        exit (84);
    } else
        key->drop = new_key;
    return (0);
}

int key_quit(key_p *key, char *str)
{
    int new_key = recup_char_key(str);

    if (new_key == -1) {
        my_printf("Bad input for key quit\n");
        exit (84);
    } else
        key->quit = new_key;
    return (0);
}
