##
## EPITECH PROJECT, 2020
## PSU_42sh_2019
## File description:
## Makefile
##

NAME		=	42sh
TEST_NAME	=	test_42sh

CC			=	gcc
FLAGS		=	-W -Wall -Wextra
D_FLAGS		=	-g
T_FLAGS		=	-lcriterion --coverage

DELTA		=	$$(echo "$$(tput cols)-47"|bc)

LIB_DIR		=	lib/
LIB_LIB		=	$(LIB_DIR)libmy.a
LIB_INC		=	$(LIB_DIR)include/

LIBS		=	-L -lmy

SRC_DIR		=	src/
INC_DIR		=	include/
OBJ_DIR		=	objs/
OBJ_DIR_TEST	=	objs_test/
SRC_TEST_DIR	=	tests/

SRC_TEST	=	\
test_criterion/test_one.c

SRC_M	=	\
main.c

SRC_BASE	=	\
excec/error_handling_excec.c \
builtin/env/ges_env/ges_env.c \
shell/recup_input.c \
shell/shell.c \
shell/signal/fct_signal.c \
shell/tools_shell.c \
shell/ges_input.c \
pwd/ges_pwd.c \
builtin/exit/my_exit.c \
builtin/env/setenv/my_setenv.c \
builtin/env/setenv/tools_set_env.c \
builtin/env/unsetenv/my_unsetenv.c \
builtin/change_directory/my_cd.c \
excec/my_exe.c \
excec/tools_exe.c \
builtin/env/ges_env/tools_env.c \
shell/separator.c \
shell/error_parsing.c \
pipe/ges_pipe.c \
pipe/tools_pipe.c \
redirect/redirect.c \
alias/display_alias.c \
alias/ges_alais.c \
alias/set_up_alias.c \
alias/check_alias.c \
alias/unalias/my_unalias.c \
echo/my_echo.c \
shell/operators/operator_loop.c \
shell/operators/op_errors.c \
shell/operators/cmd_split.c \
variable/check_env.c \
variable/tools_var.c \
variable/init_var.c \
variable/ges_var.c \
variable/set_var.c \
variable/tools_set_var.c \
variable/unset_var.c \
auto_completion/ges_compl.c \
where/my_where.c \
which/my_which.c \
repeat/my_reapeat.c \
redirect/left_redir.c \
redirect/tools_redirect.c \
globbing/globbing.c \

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
SRCS_TEST	=	$(addprefix $(SRC_TEST_DIR), $(SRC_TEST))
OBJS_TEST	=	$(addprefix $(OBJ_DIR_TEST), $(SRC_TEST:.c=.o))
SRC_MAIN	=	$(addprefix $(SRC_DIR), $(SRC_M));
MAIN_OBJ	=	$(addprefix $(OBJ_DIR), $(SRC_M:.c=.o))
NB			=	$(words $(SRC_BASE))
NB_TEST		=	$(words $(SRC_TEST))
INDEX		=	0
INDEX_TEST	=	0

all :
	@make -C $(LIB_DIR)
	@make -j $(NAME)

$(NAME):		$(LIB_LIB) $(OBJ_DIR) $(MAIN) $(MAIN_OBJ) $(OBJS)
	@$(CC) $(FLAGS) $(D_FLAGS) $(OBJS) $(MAIN_OBJ) -o $(NAME) \
		-I $(INC_DIR) \
		-I $(LIB_INC) \
		$(LIBS) \
		$(LIB_LIB)
	@printf "\r\033[48;5;15;38;5;25m✅ MAKE $(NAME)\033[0m\033[K\n"

$(TEST_NAME):		$(LIB_LIB) $(OBJ_DIR) $(OBJS) $(OBJ_DIR_TEST) $(OBJS_TEST)
	@$(CC) $(OBJS) $(OBJS_TEST) -o $(TEST_NAME) \
		-I $(INC_DIR) \
		-I $(LIB_INC) \
		$(LIBS) \
		$(LIB_LIB) \
		$(T_FLAGS)
	@printf "\r\033[48;5;15;38;5;25m✅ MAKE $(TEST_NAME)\033[0m\033[K\n"

$(LIBFT_LIB):
	@make -C $(LIB_DIR)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR_TEST) :
	@mkdir -p $(OBJ_DIR_TEST)
	@mkdir -p $(dir $(OBJS_TEST))

$(MAIN)%.o : $(SRC_M)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) $(D_FLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIB_INC)

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval COLOR=$(shell echo $$(($(PERCENT)%35+196))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB)))))
	@printf "\r\033[38;5;11m⌛ MAKE %10.10s : %2d%% \033[48;5;%dm%*s\033[0m%*s\033[48;5;255m \033[0m \033[38;5;11m %*.*s\033[0m\033[K" $(NAME) $(PERCENT) $(COLOR) $(DONE) "" $(TO_DO) "" $(DELTA) $(DELTA) "$@"
	@$(CC) $(FLAGS) $(D_FLAGS) -c $< -o $@\
		-I $(INC_DIR)\
		-I $(LIB_INC)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

$(OBJ_DIR_TEST)%.o :	$(SRC_TEST_DIR)%.c | $(OBJ_DIR_TEST)
	@$(eval DONE=$(shell echo $$(($(INDEX_TEST)*20/$(NB_TEST)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX_TEST)*100/$(NB_TEST)))))
	@$(eval COLOR=$(shell echo $$(($(PERCENT)%35+196))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX_TEST)*20/$(NB_TEST)))))
	@printf "\r\033[38;5;11m⌛ MAKE %10.10s : %2d%% \033[48;5;%dm%*s\033[0m%*s\033[48;5;255m \033[0m \033[38;5;11m %*.*s\033[0m\033[K" $(TEST_NAME) $(PERCENT) $(COLOR) $(DONE) "" $(TO_DO) "" $(DELTA) $(DELTA) "$@"
	@$(CC) $(FLAGS) -c $< -o $@\
		-I $(INC_DIR)\
		-I $(LIB_INC)
	@$(eval INDEX=$(shell echo $$(($(INDEX_TEST)+1))))

test:
	@make -C $(LIB_DIR)
	@make -j $(TEST_NAME)
	./$(TEST_NAME)

show_coverage:	test
	lcov --capture --directory ./ --output-file rapport.info
	genhtml -o ./report -t "Coverage" rapport.info
	xdg-open ./report/index.html &> /dev/null

clean:			cleanlib
	@rm -rf $(OBJ_DIR)
	@printf "\r\033[38;5;202m✖ clean $(NAME)\033[0m\033[K\n"

cleanlib:
	@make -C $(LIB_DIR) clean

cleantest:
	@rm -rf $(OBJ_DIR_TEST)
	@printf "\r\033[38;5;202m✖ clean $(TEST_NAME)\033[0m\033[K\n"

fclean:			clean fcleanlib fcleantest
	@rm -f $(NAME)
	@printf "\r\033[38;5;196m❌ fclean $(NAME)\033[0m\033[K\n"

fcleanlib:		cleanlib
	@make -C $(LIB_DIR) fclean

fcleantest:		cleantest
	@rm -rf $(TEST_NAME)
	@printf "\r\033[38;5;196m❌ fclean $(TEST_NAME)\033[0m\033[K\n"

re:				fclean all

relib:			fcleanlib $(LIB_LIB)

.PHONY :		fclean clean re relib cleanlib fcleanlib
