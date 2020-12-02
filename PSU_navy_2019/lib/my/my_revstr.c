/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Function that reverses a string.
*/

char *my_revstr(char *str)
{
    int p = 0;
    int u = 0;

    while (str[p] != '\0') {
        p++;
    }
    p--;
    while (u < p) {
        char tampo;
        tampo = str[u];
        str[u] = str[p];
        str[p] = tampo;
        u++;
        p--;
    }
    return (str);
}