/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include "my.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

struct playeur_one
{
    char **map_p;
    char **map_e;
    int pid;
    char *input;
};

typedef struct check_error
{
    char *tmp;
} s_check;

/*-------------tools------------*/
int tireh(char *str);
void display_map(char **map);
char **recup_info_file(char *filepath);
void catch_game(int sig);

int start_serveur(int pid);
char *get_next_line(int fd);
void print_game_pad(char **map_p, char **map_e);
void print_wait(void);
char **modify_map(char **map, char *input);
char **modify_map_recup(char **map, char *input, int glo);
int check_win(char **map);

int send_signal(struct playeur_one *p_o);
void send_hit_or_not(char *str, struct playeur_one *p_o);
char convert_signal_1(int nb);
char convert_signal_2(int nb);
int convert_intput(struct playeur_one *p_o);
int convert_input_nb(struct playeur_one *p_o);
void check_recup(int glo, struct playeur_one *p_o);
int send_win(struct playeur_one *p_o, int glo);

/*--------------map-------------*/
char **fill_info_in_map(char *filepath, char **map);
int check_file(char **file);
int check_it_or_not(char *input, char **map);
int count_line(char **file);
int check_it_or_not(char *input, char **map);
int check_input(char *input);
int check_value(char **file, s_check *s);
int init_first_playeur(struct playeur_one *p_o, char *filepath);
char **creat_map(char **map);
int take_imput_line(struct playeur_one *p_o);
void start_client(void);
int start_game(struct playeur_one *p_o, int ac, char **av);

int play_usr_one(struct playeur_one *p_o);
int play_usr_two(struct playeur_one *p_o);

#endif /* !NAVY_H_ */
