/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

/*
** struct vector
*/

struct vector
{
    int x;
    int y;
};

int open_file(char const *file);

/*
** mouvements.c
*/

int get_pos_p(char **map, int *colum, int *line);
void move_up(int col, int line, char **map, char **tmp);
void move_down(int col, int line, char **map, char **tmp);
void move_right(int col, int line, char **map, char **tmp);
void move_left(int col, int line, char **map, char **tmp);

/*
** count
*/

int count_col(char *buffer);
int count_line(char *buffer);

/*
** Check win loose
*/

int check_loose(char **map);
int check_win(char **map, char **tmp);
int check_how_many_x(char **map);

/*
** check_valid_map
*/

int check_valid_map(char *buffer);


#endif /* !SOKOBAN_H_ */
