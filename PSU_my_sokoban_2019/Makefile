##
## EPITECH PROJECT, 2019
## pushswap
## File description:
## Makefile
##

SRCS = main.c sokoban.c movements.c tools.c check.c check_map.c

LIBPATH = lib/my/

NAME = my_sokoban

all : ${NAME}

${NAME} :
	make -C ${LIBPATH} all
	gcc -Wall -Wextra -lncurses -g -o ${NAME} ${SRCS} -L lib/my -lmy -I include

clean :
	rm ${NAME}

fclean : clean
	make -C ${LIBPATH} fclean

re : clean fclean all