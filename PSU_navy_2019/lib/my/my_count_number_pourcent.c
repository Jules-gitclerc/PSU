/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** count_number_pourcent
*/

#include "my.h"

int my_count_number_pourcent(char const *format)
{
    int u = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && (format[i + 1] == 's' || format[i + 1] == 'i'
        || format[i + 1] == 'c' || format[i + 1] == 'o' || format[i + 1] == 'x'
        || format[i + 1] == 'X' || format[i + 1] == 'b'
        || format[i + 1] == 'u' || format[i + 1] == 'p'
        || format[i + 1] == 'S' || format[i + 1] == ' '
        || format[i + 1] == 'd' || format[i + 1] == 't'))
            u++;
    }
    return (u);
}
