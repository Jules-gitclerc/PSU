##
## EPITECH PROJECT, 2019
## day10
## File description:
## Makefile
##

HEADER = my.h

HEADPATH = ../../include/

SRCS = my_getnbr.c my_isneg.c my_putchar.c my_put_nbr.c my_putstr.c my_revstr.c my_strcat.c my_strcmp.c my_strcpy.c my_strdup.c my_str_isalpha.c my_str_islower.c my_str_isnum.c my_str_isprintable.c my_str_isupper.c my_strlen.c my_strlowcase.c my_strncat.c my_strncmp.c my_strncpy.c my_strstr.c my_strupcase.c my_swap.c my_putnbr_base.c tools1.c tools2.c my_printf.c tools3.c

OBJ = ${SRCS:.c=.o}

NAME = libmy.a

LIBPATH = ../../

all : ${NAME}

${NAME} :
	gcc -c ${SRCS}
	ar rc ${NAME} ${OBJ}
	cp ${HEADER} ${HEADPATH}

clean :
	rm ${OBJ}
	rm ${NAME}

fclean : clean

re : fclean all