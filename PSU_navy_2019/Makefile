##
## EPITECH PROJECT, 2019
## PSU_navy_2019
## File description:
## Makefile
##

CC = gcc

SRCS = 	main.c \
		tools.c \
		get_next_line.c \
		fill_map.c \
		check_error.c \
		check_pos.c \
		game.c \
		recup_input.c \
		print_game_pad.c \
		signal.c \
		check_hit_or_not.c \
		decrypt_signal.c \
		modify_map.c \
		tools_game_loop.c \
		convert_input.c \
		game_loop.c

LIBPATH = ./lib/my/

OBJ = $(SRCS:.c=.o)

NAME = navy

RM = rm -f

LIBFLAGS = -L lib/my -lmy

CFLAGS = -W -Wall -Wextra -I include/ -Ilib/my/

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