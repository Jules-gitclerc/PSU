/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** debug_mode.c
*/

#include "tetris.h"

int count_tetrimino(trimino_d *mino)
{
    int count = 0;

    for (trimino_d *cur = mino->next; cur != NULL; cur = cur->next, count++);
    if (count <= 2) {
        exit (84);
    }
    return (count);
}

void print_well_key(int key)
{
    if (key == 32) {
        my_printf("(Space)\n");
        return;
    } if (key == 1) {
        my_printf("^EOA\n");
        return;
    } if (key == 2) {
        my_printf("^EOB\n");
        return;
    } if (key == 3) {
        my_printf("^EOC\n");
        return;
    } if (key == 4) {
        my_printf("^EOD\n");
        return;
    }
    my_printf("%c\n", key);
}

void print_info_key(key_p *key)
{
    my_printf("Key Left :  ");
    print_well_key(key->left);
    my_printf("Key Right :  ");
    print_well_key(key->right);
    my_printf("Key Turn :  ");
    print_well_key(key->turn);
    my_printf("Key Drop :  ");
    print_well_key(key->drop);
    my_printf("Key Quit :  ");
    print_well_key(key->quit);
    my_printf("Key Pause :  ");
    print_well_key(key->pause);
    my_printf("Next :  ");
    if (key->next == 0)
        my_printf("Yes\n");
    else
        my_printf("No\n");
}

int take_imput_line(void)
{
    char *letter = NULL;
    int read_c = 0;

    while (letter == NULL) {
        read_c = read(0, &letter, 1);
        if (read_c >= 1)
            break;
    }
    return (0);
}

void print_debug_mode(trimino_d *mino, key_p *key)
{
    my_printf("*** DEBUG MODE ***\n");
    print_info_key(key);
    my_printf("Level :  %i\n", key->level);
    my_printf("Size :  %i*%i\n", key->line, key->colum);
    my_printf("Tetriminos :  %i\n", count_tetrimino(mino));
    for (trimino_d *cur = mino->next; cur != NULL; cur = cur->next) {
        my_printf("Tetriminos :  Name %s :  ", cur->name);
        if (cur->error == 1)
            my_printf("Error\n");
        else {
            my_printf("Size %i*%i :  Color %i :\n", cur->nb_colum,
                                        cur->nb_line, cur->color);
            for (int i = 0; cur->triminos[i] != NULL; i++)
                my_printf("%s\n", cur->triminos[i]);
        }
    }
    my_printf("Press any key to start Tetris");
    take_imput_line();
}
