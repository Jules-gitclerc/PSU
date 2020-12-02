/*
** EPITECH PROJECT, 2019
** jules.clerc@epitech.eu
** File description:
** checks if parameter is negative
*/

void    my_putchar(char c);

int     my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}