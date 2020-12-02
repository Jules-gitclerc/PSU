##
## EPITECH PROJECT, 2019
## PSU_tetris_2019
## File description:
## Makefile
##

SRCS =	./src/main.c \
		./src/open_fill/open_fill_tetris.c \
		./src/open_fill/open_fill_tetris_bis.c \
		./src/open_fill/tools_open.c \
		./src/open_fill/tools_open_bis.c \
		./src/debug_mode.c \
		./src/parsing/fct_flag_bis.c \
		./src/parsing/fct_flag_info_bis.c \
		./src/parsing/fct_flag_info.c \
		./src/parsing/fct_flag.c \
		./src/parsing/ges_flag.c \
		./src/game/game_loop.c \
		./src/ges_map/create_map.c \
		./src/game/tools_in_game.c \
		./src/open_fill/check_compatibity.c \
		./src/game/moove_tetris.c \
		./src/game/suppr_line.c

LIBPATH = ./lib/my/

OBJ = $(SRCS:.c=.o)

NAME = tetris

RM = rm -f

LIBFLAGS = -L lib/my -lmy

CFLAGS = -g -W -Wall -Wextra -I include/ -Ilib/my/ -lncurses

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
