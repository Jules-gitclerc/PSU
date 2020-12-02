/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** function taht counts and returns number of strings
*/

void my_putchar(char letters);

int my_strlen(char const *str)
{
    int v = 0;

    for (; str[v] != '\0'; v++);
    return (v);
}
