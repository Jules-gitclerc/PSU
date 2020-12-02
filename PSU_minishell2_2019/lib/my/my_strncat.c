/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_strncat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (dest[i])
        i++;
    j = i + nb;
    while (i < j) {
        dest[i] = src[k];
        i++;
        k++;
    }
    dest[j] = '\0';
    return (dest);
}