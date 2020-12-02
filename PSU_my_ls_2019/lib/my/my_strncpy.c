/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_strncpy
*/

char    *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > i)
        dest[i] = '\0';
    return (dest);
}