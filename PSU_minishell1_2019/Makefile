##
## EPITECH PROJECT, 2019
## pushswap
## File description:
## Makefile
##

SRCS = main.c env.c my_exec.c tool_env.c tool_str.c my_setenv.c my_exit.c

LIBPATH = lib/my/

NAME = mysh

all : ${NAME}

${NAME} :
	make -C ${LIBPATH} all
	gcc -Wall -Wextra -o ${NAME} ${SRCS} -L lib/my -lmy -I include

clean :
	rm ${NAME}

fclean : clean
	make -C ${LIBPATH} fclean

re : clean fclean all