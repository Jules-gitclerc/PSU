##
## EPITECH PROJECT, 2019
## day10
## File description:
## Makefile
##

HEADER = my.h

HEADPATH = ../../include/

SRCS =  my_compute_power_rec.c\
		my_compute_square_root.c\
		my_count_number_pourcent.c\
		my_str_to_word_array.c\
		my_clear_str.c\
		my_getnbr.c\
		my_printf.c\
		my_put_binary.c\
		my_put_hexa_capitalize.c\
		my_put_hexa.c\
		my_put_nbr.c\
		my_put_octal.c\
		my_put_pointeur.c\
		my_put_str_for_s.c\
		my_put_unsigned_int.c\
		my_put_unsigned_str.c\
		my_putchar.c\
		my_putstr.c\
		my_revstr.c\
		my_strcat.c\
		my_strcpy.c\
		my_strlen.c\
		my_strncat.c\
		my_strncmp.c\
		my_strncpy.c\
		my_strstr.c\
		my_supergetnbr.c\
		my_swap.c\
		tools_my_printf.c\
		tools_my_printf2.c\
		tools_my_printf3.c\
		tools3.c\
		my_strcmp.c

RM = rm -f

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
	${RM} ${OBJ}
	${RM} ${NAME}

fclean : clean
	${RM} ${HEADPATH}${HEADER}
	${RM} ${LIBPATH}${NAME}

re : fclean all
