/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** cmd_split
*/

#include <stdlib.h>
#include <stdio.h>

int count_ops(char *cmd)
{
    int count = 0;

    for (int i = 0; cmd[i] != '\0'; i++)
        if ((cmd[i] == '&' && cmd[i + 1] == '&') || \
            (cmd[i] == '|' && cmd[i + 1] == '|'))
            count++;
    return (count);
}

char *get_operators(char *cmd)
{
    char *ops = NULL;
    int count = count_ops(cmd);

    ops = malloc(sizeof(char) * (count + 2));
    if (ops == NULL)
        return (NULL);
    ops[0] = '*';
    for (int i = 0, count = 1; cmd[i] != '\0'; i++) {
        if (cmd[i] == '&' && cmd[i + 1] == '&') {
            ops[count] = '&';
            count++;
        }
        if (cmd[i] == '|' && cmd[i + 1] == '|') {
            ops[count] = '|';
            count++;
        }
    }
    ops[count + 1] = '\0';
    return (ops);
}

int my_opcmp(char **seps, char *str, int run)
{
    if (str[run] == seps[0][0] && str[run + 1] == seps[0][1])
        return (1);
    if (str[run] == seps[1][0] && str[run + 1] == seps[1][1])
        return (1);
    return (0);
}

char **my_splitter(char *str, char **wrd_tab, int nb, char **seps)
{
    int y = 0;
    int c = 0;
    int tmp = 0;

    wrd_tab = malloc(sizeof(char *) * (nb + 1));
    if (wrd_tab == NULL)
        return (NULL);
    wrd_tab[nb] = NULL;
    for (int i = 0; i < nb; i++, c++) {
        tmp = c;
        for (y = 0; my_opcmp(seps, str, c) != 1 && str[c] != '\0'; c++, y++);
        wrd_tab[i] = malloc(sizeof(char) * (y + 1));
        if (wrd_tab[i] == NULL)
            return (NULL);
        wrd_tab[i][y] = '\0';
        c = (tmp == 0) ? tmp : tmp + 1;
        for (int o = 0; my_opcmp(seps, str, c) != 1 && str[c] != '\0'; o++, c++)
            wrd_tab[i][o] = str[c];
    }
    return (wrd_tab);
}

char **ft_split_2_sep(char *str, char *sep1, char *sep2)
{
    char **wrd_tab = NULL;
    int nb = 1;
    char *seps[3] = {sep1, sep2, 0};

    if (str[0] == '\0')
        return (wrd_tab);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep1[0] && str[i + 1] == sep1[1])
            nb++;
        if (str[i] == sep2[0] && str[i + 1] == sep2[1])
            nb++;
    }
    wrd_tab = my_splitter(str, wrd_tab, nb, seps);
    return (wrd_tab);
}