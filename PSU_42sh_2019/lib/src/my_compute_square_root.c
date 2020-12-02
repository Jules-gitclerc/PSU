/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** I like squarre root.
*/

int my_compute_square_root(int nb)
{
    int test = 1;

    while (test * test < nb && test <= 46340)
        test++;
    if (test * test == nb)
        return (test);
    else
        return (0);
}
