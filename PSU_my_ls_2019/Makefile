##
## EPITECH PROJECT, 2019
## pushswap
## File description:
## Makefile
##

SRCS = main.c my_ls.c

LIBPATH = lib/my/

NAME = my_ls

all : ${NAME}

${NAME} :
	make -C ${LIBPATH} all
	gcc -Wall -Wextra -g -o  ${NAME} ${SRCS} -L lib/my -lmy -I include

clean :
	rm ${NAME}

fclean : clean
	make -C ${LIBPATH} fclean

re : clean fclean all