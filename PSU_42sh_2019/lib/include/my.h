/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** lib
*/

#ifndef MY_H_
#define MY_H_
typedef __builtin_va_list va_list;

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime (int nb);
int my_put_nbr(int nb);
int my_printf(const char *format, ...);
int my_count_number_pourcent(char const *format);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int search_pourcent(char const *format);
int sum_stdarg(char const *format, int b, va_list tp);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char  const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char  const *s1, char const *s2, int n);
char *my_strncpy (char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
int my_put_binary(int nb);
int flags(char const *format, int u);
int print_carat(char const *format, int i);
int my_put_hexa(unsigned int nb);
int my_put_pointeur(unsigned long int nb);
int my_put_octal(int nb);
int my_put_hexa_capitalize(int nb);
void my_swap(char *a, char *b);
int my_put_unsigned_int(unsigned int nb);
int my_put_s(char *str);
int print_printf(char const *format, void (*pointeur[10])(va_list),
                int d, va_list arg);
char *my_supergetnbr(int nb);
int my_put_unsigned_str(unsigned char const *str);
void pourcent_c(va_list arg);
void pourcent_i(va_list arg);
void pourcent_s(va_list arg);
void pourcent_o(va_list arg);
void pourcent_hexa(va_list arg);
void pourcent_hexa_capit(va_list arg);
void pourcent_b(va_list arg);
void pourcent_u(va_list arg);
void pourcent_p(va_list arg);
void pourcent_ss(va_list arg);
void pourcent_t(va_list arg);
char **my_str_to_word_array(char *str, char letter);
char *my_clean_str(char *str);
int my_str_isnum(char *str);

#endif /* !MY_H_ */
