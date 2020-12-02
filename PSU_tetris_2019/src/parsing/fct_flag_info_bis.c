/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** fct_flag_info_bis.c
*/

#include "tetris.h"

int conf_debug(key_p *key, char *str)
{
    return (1);
}

int conf_next(key_p *key, char *str)
{
    key->next = 1;
    return (0);
}
