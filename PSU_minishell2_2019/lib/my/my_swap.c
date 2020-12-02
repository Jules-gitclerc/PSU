/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** my_swap
*/

void    my_swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}