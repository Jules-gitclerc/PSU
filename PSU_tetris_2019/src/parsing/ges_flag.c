/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** ges_flag.c
*/

#include "tetris.h"
#include <ncurses.h>

arg_inp key_arg[] = {
    {"--help", NULL, 0, help},
    {"--key-left=", "-l", 1, key_left},
    {"--key-right=", "-r", 1, key_right},
    {"--key-turn=", "-t", 1, key_turn},
    {"--key-drop=", "-d", 1, key_drop},
    {"--key-quit=", "-q", 1, key_quit},
    {"--key-pause=", "-p", 1, key_pause},
    {"--map-size", NULL, 1, conf_map_size},
    {"--level", "-L", 1, conf_level},
    {"--without-next", "-w", 0, conf_next},
    {"--debug", "-D", 0, conf_debug},
    {NULL, NULL, 0, NULL}
};

int help(key_p *key, char *str)
{
    my_printf("Usage: ./tetris [options]\nOptions:\n --help\tDisplay ");
    my_printf("this help\n -L --level={num}\tStart Tetris at level num");
    my_printf(" (def: 1)\n -l --key-left={K}\tMove the tetrimino LEFT ");
    my_printf("using the K key (def: left arrow)\n -r --key-right={K}\t");
    my_printf("Move the tetrimino RIGHT using the K key (def: right arrow)");
    my_printf("\n -t --key-turn={K}\tTURN the tetrimino clockwise 90d");
    my_printf("using  the K key (def: top arrow)\n -d --key-drop={K}\t");
    my_printf("DROP the tetrimino using the K key (def: down arrow)\n ");
    my_printf("-q --key-quit={K}\tQUIT the game using the K key");
    my_printf(" (def: ‘q’ key)\n -p --key-pause={K}\tPAUSE/RESTART");
    my_printf(" the game using the K key (def: space bar)\n ");
    my_printf("--map-size={row,col}\tSet the numbers of rows and");
    my_printf(" columns of the map (def: 20,10)\n -w --without-next\t");
    my_printf("Hide next tetrimino (def: false)\n -D --debug\t");
    my_printf("Debug mode (def: false)\n");
    exit (0);
}

int print_error(key_p *key, char **arg, int r)
{
    if (key_arg[key->i].name_full == NULL) {
        my_printf("Bad input: %s doesn't exciste\n", arg[r]);
        exit (84);
    }
    return (0);
}

int loop_parsing(key_p *key, char **arg, int act)
{
    for (key->i = 0; key_arg[key->i].name_full != NULL; key->i++) {
        if (my_strncmp(key_arg[key->i].name_full, arg[key->r],
            my_strlen(key_arg[key->i].name_full)) == 0) {
                act += key_arg[key->i].function(key, recup_key(arg[key->r]));
                break;
        }
        if (key_arg[key->i].name_last != NULL &&
        my_strncmp(key_arg[key->i].name_last, arg[key->r],
        my_strlen(key_arg[key->i].name_last)) == 0) {
            if (key_arg[key->i].number_arg == 0) {
                act += key_arg[key->i].function(key, NULL);
                break;
            } else if (arg[key->r + 1] != NULL) {
                act += key_arg[key->i].function(key, arg[key->r + 1]);
                key->r += 1;
                break;
            }
        }
    }
    return (act);
}

int parsing_arg(key_p *key, char **arg)
{
    int act = 0;

    init_classic_key(key);
    for (key->r = 1; arg[key->r] != NULL; key->r++) {
        act = loop_parsing(key, arg, act);
        if (key_arg[key->i].name_full == NULL) {
            my_printf("Bad input: %s doesn't exciste\n", arg[key->r]);
            exit (84);
        }
    }
    return (act);
}