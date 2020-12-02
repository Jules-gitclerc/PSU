/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** Write a function that copies a string into another.
*/

char *my_strcpy(char *dest, char const *src)
{
    unsigned int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
