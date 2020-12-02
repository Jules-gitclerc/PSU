/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_octal
*/

void my_putchar(char lettre);

int my_put_octal(int nb)
{
    if (nb < 8)
    {
        my_putchar(48 + nb);
    }
    if (nb >= 8)
    {
        my_put_octal(nb / 8);
        my_putchar(nb % 8 + 48);
    }
    return (0);
}