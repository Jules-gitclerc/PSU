/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** change number
*/

void my_swap(char *a, char *b)
{
    int tampo;

    tampo = *b;
    *b = *a;
    *a = tampo;
}
