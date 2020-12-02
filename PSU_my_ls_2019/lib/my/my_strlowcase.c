/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_strlowcase
*/

char    *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] += 32;
    return (str);
}