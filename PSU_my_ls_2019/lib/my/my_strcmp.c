/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_strcmp
*/

int     my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    
    while (s1[i] == s2[i] && s1[i])
        i++;
    return (s1[i] - s2[i]);
}