/*
** EPITECH PROJECT, 2019
** day09
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>

char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char *to_find);
char *my_strupcase(char *str);
char *my_strdup(char const *str);
int is_alphanum(char c);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
void my_putchar(char c);
void my_swap(int *a, int *b);
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
char **my_str_to_word_array(char const *str);
int     is_alphanum(char c);

#endif /* !MY_H_ */