/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (dest[i])
        i++;
    while (src[j])
        j++;
    j += i;
    while (i < j) {
        dest[i] = src[k];
        i++;
        k++;
    }
    dest[j] = '\0';
    return (dest);
}