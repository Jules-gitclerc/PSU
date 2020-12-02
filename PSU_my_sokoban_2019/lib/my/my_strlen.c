/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** returns the length of a string
*/

int     my_strlen(char const *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}