##
## EPITECH PROJECT, 2019
## dante_generateur
## File description:
## Makefile
##

CC = gcc

SRCS = 	main.c \
		env/init_env.c \
		env/my_env.c \
		env/my_setenv.c \
		env/my_unsetenv.c \
		env/tools_env.c \
		command.c \
		my_cd.c \
		my_exec.c \
		my_exit.c \
		parsing.c \
		utils_str.c \
		tools.c \
		my_pipe.c

NAME = mysh

OBJ = $(SRCS:.c=.o)

RM = rm -f

LIBPATH = ./lib/my

LIBFLAGS = -L lib/my -lmy

CFLAGS =  -g -W -Wall -Wextra -I ./include/ -Ilib/my/

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBPATH) all
	$(CC) $(OBJ) $(CFLAGS) $(LIBFLAGS) -o $(NAME)

clean :
	$(RM) $(NAME)
	$(RM) $(OBJ)

fclean : clean
		make -C $(LIBPATH) fclean

re : clean fclean all

.PHONY: all clean fclean re