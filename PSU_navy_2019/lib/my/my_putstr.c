/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** write the characters of a string, one by one.
*/

void my_putchar(char letter);

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}
