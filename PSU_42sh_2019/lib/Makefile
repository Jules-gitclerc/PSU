##
## EPITECH PROJECT, 2019
## day10
## File description:
## Makefile
##

NAME		=	libmy.a

CC			=	gcc
AR			=	ar rc
MKDIR		=	mkdir -p
RM			=	/bin/rm -rf

W_FLAGS		=	-W -Wall -Wextra
D_FLAGS		=	-g
FLAGS		=	$(W_FLAGS)

DELTA		=	$$(echo "$$(tput cols)-47"|bc)

SRC_DIR		=	src/
INC_DIR		=	include/
OBJ_DIR		=	objs/

SRC_BASE	=	\
my_compute_power_rec.c\
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
my_strcmp.c\
my_str_is_num.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

all:
	@make -j $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@printf "\r\033[48;5;15;38;5;25m✅ MAKE $(NAME)\033[0m\033[K\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval COLOR=$(shell echo $$(($(PERCENT)%35+196))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB)))))
	@printf "\r\033[38;5;11m⌛ MAKE %10.10s : %2d%% \033[48;5;%dm%*s\033[0m%*s\033[48;5;255m \033[0m \033[38;5;11m %*.*s\033[0m\033[K" $(NAME) $(PERCENT) $(COLOR) $(DONE) "" $(TO_DO) "" $(DELTA) $(DELTA) "$@"
	@$(CC) $(FLAGS) -c $< -o $@\
		-I $(INC_DIR)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)
	@$(MKDIR) $(dir $(OBJS))

clean:
	@$(RM) $(OBJ_DIR)
	@printf "\r\033[38;5;202m✖ clean $(NAME)\033[0m\033[K\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "\r\033[38;5;196m❌ fclean $(NAME)\033[0m\033[K\n"

re: fclean all

.PHONY: all clean fclean re