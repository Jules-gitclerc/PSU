/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_strncmp
*/

int     my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n == 0)
        return (0);
    while (s1[i] == s2[i] && i + 1 < n && s1[i])
        i++;
    return (s1[i] - s2[i]);
}