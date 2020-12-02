/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** him give one number and write in the console
*/

void my_putchar(char lettre);

int my_put_nbr(int nb)
{
    if (nb < 0)
    {
        my_putchar('-');
        if (nb == -2147483648)
        {
            my_putchar('2');
            nb = -147483648;
        }
        nb = -nb;
    }
    if (nb < 10)
    {
        my_putchar(48 + nb);
    }
    else
    {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}
