/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_hexa
*/

void my_putchar(char lettre);

int my_put_hexa(unsigned int nb)
{
    if (nb >= 16)
        my_put_hexa(nb / 16);
    if ((nb % 16) > 9)
        my_putchar(nb % 16 + 87);
    else
        my_putchar(nb % 16 + 48);
    return (0);
}
