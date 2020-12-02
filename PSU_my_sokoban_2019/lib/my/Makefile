##
## EPITECH PROJECT, 2019
## day10
## File description:
## Makefile
##

HEADER = my.h

HEADPATH = ../../include/

SRCS = my_putchar.c my_put_nbr.c my_putstr.c my_strlen.c tools1.c tools2.c tools3.c my_printf.c my_putnbr_base.c

OBJ = ${SRCS:.c=.o}

NAME = libmy.a

LIBPATH = ../

all : ${NAME}

${NAME} :
	gcc -c ${SRCS}
	ar rc ${NAME} ${OBJ}
	cp ${HEADER} ${HEADPATH}
	cp ${NAME} ${LIBPATH}

clean :
	rm ${OBJ}
	rm ${NAME}

fclean : clean
	rm ${LIBPATH}${NAME}

re : fclean all