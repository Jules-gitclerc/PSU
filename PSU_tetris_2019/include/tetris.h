/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>
#include <getopt.h>
#include <ncurses.h>
#include "my.h"

/*---struct_tetris_mino---*/
typedef struct triminos_data trimino_d;
struct triminos_data {
    int color;
    int error;
    int nb_line;
    int nb_colum;
    char **triminos;
    char *name;
    trimino_d *next;
};

typedef struct keyborad {
    int left;
    int right;
    int turn;
    int drop;
    int quit;
    int pause;
    int line;
    int colum;
    int level;
    int next;
    int i;
    int r;
    int score;
} key_p;

typedef struct game {
    char **map;
    char **tetris;
    int act;
} s_game;
typedef struct s_arg
{
    char *name_full;
    char *name_last;
    int number_arg;
    int (*function)();
} arg_inp;

/*-------open_fill--------*/
void open_floder(trimino_d *mino);
int my_stat(char const *file);
int check_line_full(char **map);
char *recup_teris(char *str);
char *recup_line_info(char *str);
int recup_number(char *str);
void check_end_tab(trimino_d *mino);
int check_tetris(char *str);
void check_comp(trimino_d *mino);
char *take_name(char *b_name);
int check_first_line_file(char *str);
char *readapting_str(char *str);
void init_well_tetris_mode(trimino_d *cur, char *file, char *str);
void init_wrong_tetris_node(trimino_d *cur, char *file);

/*----------map----------*/
void game_loop(key_p *key, trimino_d *mino);

/*--------ges_map--------*/
char **init_map(int line, int colum);

/*---------flags---------*/
int recup_char_key(char *str);
char *recup_key(char *str);
void init_classic_key(key_p *key);

/*-------debug_mode------*/
void print_debug_mode(trimino_d *mino, key_p *key);

/*--------parsing--------*/
int parsing_arg(key_p *key, char **arg);

/*----------key----------*/
int key_left(key_p *key, char *str);
int key_right(key_p *key, char *str);
int key_turn(key_p *key, char *str);
int key_drop(key_p *key, char *str);
int key_quit(key_p *key, char *str);
int key_pause(key_p *key, char *str);
int help(key_p *key, char *str);

/*---------info----------*/
int conf_map_size(key_p *key, char *str);
int conf_level(key_p *key, char *str);
int conf_next(key_p *key, char *str);
int conf_debug(key_p *key, char *str);

/*---------game---------*/
char **select_trimino(trimino_d *mino);
char **moving_forward(char **map, int end_map);
int check_end_moove(char **map);
char **stone_statue(char **map);
char **moove_right(char **map, int end_map, int col_max, key_p *key);
char **moove_left(char **map, int end_map, int col_max, key_p *key);
char **pause_tetris(char **map, int end_map, int col_max, key_p *key);
char **exit_game(char **map, int end_map, int col_max, key_p *key);
char **suppr_line(char **map, int i, key_p *key);
void print_map(char **map);
void display_score(key_p *key);
void init_game(s_game *game, key_p *key, trimino_d *mino);
void game_loop2(key_p *key, trimino_d *mino, s_game *game);

#endif /* !TETRIS_H_ */
