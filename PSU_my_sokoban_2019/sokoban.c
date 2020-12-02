/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main
*/

#include <stdio.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "sokoban.h"

void display_map(char **map, int count_line, int count_column)
{
    for (int i = count_line - 1; i >= 0; i--) {
        mvprintw(LINES / 2 - count_line / 2 + i, COLS
                / 2 - count_column / 2, map[i]);
    }
}

void moove(int key, char **map, char **tmp)
{
    int line;
    int colum;

    get_pos_p(map, &colum, &line);
    switch (key) {
        case KEY_UP:
            move_up(colum, line, map, tmp);
            break;
        case KEY_DOWN:
            move_down(colum, line, map, tmp);
            break;
        case KEY_LEFT:
            move_left(colum, line, map, tmp);
            break;
        case KEY_RIGHT:
            move_right(colum, line, map, tmp);
            break;
    }
}

char **alloc(char *buffer)
{
    int count_line = 0;
    int count_colum = 0;
    char **map;
    int run = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            count_line++;
    for (int i = 0; buffer[i] != '\n'; i++, count_colum++);
    map = malloc(sizeof(char *) * (count_line + 1));
    map[count_line] = '\0';
    for (int i = 0; i < count_line; i++) {
        map[i] = malloc(sizeof(char) * (count_colum + 1));
        map[i][count_colum] = '\0';
    }
    for (int i = 0; i < count_line; i++) {
        for (int n = 0; buffer[run] != '\n'; n++, run++)
            map[i][n] = buffer[run];
        run++;
    }
    return (map);
}

int create_screen(char **map, int nb_line, int nb_col, char *buffer)
{
    int key;
    char **tmp;

    initscr();
    clear();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    tmp = alloc(buffer);
    while (check_win(map, tmp) == 0) {
        display_map(map, nb_line, nb_col);
        key = getch();
        moove(key, map, tmp);
        if (check_loose(map) == check_how_many_x(map))
            return (1);
    } 
    display_map(map, nb_line, nb_col);
    endwin();
    return (0);
}

int open_file(char const *file)
{
    int fd = open(file, O_RDONLY);
    struct stat *buf = malloc(sizeof(struct stat));
    int size;
    char *buffer;

    if (fd == -1)
        exit (84);
    stat(file, buf);
    size = buf->st_size;
    free(buf);
    buffer = malloc(sizeof(char) * size + 1);
    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    my_printf("%d\n", check_valid_map(buffer));
    if (check_valid_map(buffer) == 1)
        create_screen(alloc(buffer), count_line(buffer), count_col(buffer), buffer);
    else
        return (84);
    return (0);
}