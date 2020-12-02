/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** tools
*/

#include "navy.h"

void display_map(char **map)
{
    int nb = 1;

    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; map[i] != NULL && nb <= 8; i++, nb++) {
        my_printf("%i|", nb);
        for (int o = 0; map[i][o] != '\0'; o++) {
            if (map[i][o + 1] != '\0')
                my_printf("%c ", map[i][o]);
            else
                my_printf("%c\n", map[i][o]);
        }
    }
}

int tireh(char *str)
{
    if (str[0] == '-' && str[1] == 'h' && my_strlen(str) == 2) {
        my_printf("USAGE\n\t./navy [first_player_pid] navy_positions\n");
        my_printf("DESCRIPTION\n");
        my_printf("\tfirst_player_pid:  only for the 2nd player.");
        my_printf("pid of the first player.\n");
        my_printf("\tnavy_positions:  file representing the positions");
        my_printf("of the ships.\n");
        return (1);
    }
    return (0);
}

char **recup_info_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char **new = malloc(sizeof(char *) * 15);

    if (fd == -1 || new == NULL)
        return (NULL);
    for (int i = 0; (new[i] = get_next_line(fd)) != NULL; i++);
    close(fd);
    return (new);
}
