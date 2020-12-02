/*
** EPITECH PROJECT, 2019
** day09
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>

int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);
int my_putnbr_base(int nbr, char const *base);
void my_printf_nbr_hexa(va_list *list);
void my_printf_nbr_binary(va_list *list);
void my_printf_nbr_u(va_list *list);
void my_printf_nbr_p(va_list *list);
void my_printf_str(va_list *list);
void my_printf_char(va_list *list);
void my_printf_nbr(va_list *list);
void my_printf_nbr_octal(va_list *list);
void my_printf_nbr_hex(va_list *list);
int my_printf(char *src, ...);
int check_base(char const *base);
void my_putnbr_base_long(unsigned long int nbr, char const *base);
void my_printf_p(va_list *list);
int check_space(char *src, int i);
void    my_printf_sp(va_list *list);

#endif /* !MY_H_ */