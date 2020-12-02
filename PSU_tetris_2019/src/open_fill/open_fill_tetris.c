/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** open_fill_tetris
*/

#include "tetris.h"

char *read_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = my_stat(filepath);
    char *buf = malloc(sizeof(char) * size + 1);
    int read_c = read(fd, buf, size);

    buf[read_c] = '\0';
    if (read_c <= 5) {
        free (buf);
        return (NULL);
    } else
        return (buf);
}

void init_list_mino(trimino_d *mino)
{
    mino->color = -1;
    mino->nb_colum = -1;
    mino->nb_line = -1;
    mino->error = 0;
    mino->next = NULL;
    mino->triminos = NULL;
}

void add_node(trimino_d *mino, char *str, char *file)
{
    trimino_d *cur = mino;
    int indic = 0;

    if (str == NULL)
        indic = 1;
    for (; cur->next != NULL; cur = cur->next);
    cur->next = malloc(sizeof(trimino_d));
    cur = cur->next;
    if (indic == 1 || check_tetris(str) == -1
        || check_first_line_file(recup_line_info(str)) == -1)
        init_wrong_tetris_node(cur, file);
    else
        init_well_tetris_mode(cur, file, str);
}

void open_floder(trimino_d *mino)
{
    struct dirent *read;
    DIR *rep;
    char *str = NULL;

    init_list_mino(mino);
    rep = opendir("./tetriminos");
    while ((read = readdir(rep)) != NULL) {
        if (read->d_name[0] != '.' && check_well_name(read->d_name) != -1) {
            str = read_file(my_strcat("./tetriminos/", read->d_name));
            add_node(mino, str, read->d_name);
        }
    }
    closedir(rep);
    check_end_tab(mino);
}
