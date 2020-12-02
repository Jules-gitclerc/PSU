/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_strupcase
*/

char    *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if ('a' <= str[i] && str[i] <= 'z')
            str[i] -= 32;
    return (str);
}