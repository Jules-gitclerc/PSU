/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** tools
*/

int count_line(char *buffer)
{
    int i = 0;
    int count = 0;

    while (buffer[i]) {
        if (buffer[i] == '\n')
            count++;
        i++;
    }
    return (count);
}

int count_col(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n')
        i++;
    return (i);
}