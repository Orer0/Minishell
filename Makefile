
NAME = minishell

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/

INCLUDES = ./include/

SRCS =	./src/main.c\
		./src/bt_change_directory/bt_change_directory.c\
		./src/bt_change_directory/change_path.c\
		./src/bt_change_directory/new_arg.c\
		./src/bt_change_directory/build_path.c\
		./src/bt_change_directory/manag_old_pwd.c\
		./src/bt_change_directory/build_path_root.c\
		./src/bt_change_directory/error_cd.c\
		./src/ret_pwd.c\
		./src/del.c\
		./src/bt_env.c\
		./src/check_commande.c\
		./src/command_way.c\
		./src/command_way_env.c\
		./src/make_env.c\
		./src/manag_env.c\
		./src/print_env.c\
		./src/expansion_tilde.c\
		./src/expansion_dollar.c\
		./src/bt_echo.c\
		./src/error_malloc.c\
		./src/bt_unsetenv.c\
		./src/bt_setenv.c\
		./src/exe_command.c\
		./src/option.c\
		./src/usage.c\
		./src/bt_exit.c\
		./src/read_prompt.c\
		./src/manag_path.c\
		./src/command_line.c\
		./src/shell_level.c\
		./src/ft_copy_list.c\
		./src/ft_strsplit_mod.c\
		./src/utils.c\

LIB = $(LIBFT)/libft.a

BIN = $(SRCS:.c=.o)

SRC = src

OBJS_PATH = objs

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(BIN) $(INCLUDES) $(LIB)
	$(CC) $(FLAGS) $(BIN) $(LIB) -I $(INCLUDES) -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@

$(LIB):
	make -C $(LIBFT)

debug: $(BIN) $(INCLUDES) $(LIB)
	$(CC) $(FLAGS) -g3 -fsanitize=address $(BIN) $(LIB) -I $(INCLUDES) -o $(NAME)

clean:
	rm -f $(BIN)
	make clean -C $(LIBFT)

fclean:clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
