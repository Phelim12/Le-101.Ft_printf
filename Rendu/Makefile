# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/24 22:08:57 by clcreuso     #+#   ##    ##    #+#        #
#    Updated: 2018/01/10 15:48:15 by clcreuso    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

C_FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

DIR_LIB = Libft

DIR_INC = Includes

DIR_SRC = Sources

DIR_OBJ = Objects

SRCS = find_params.c ft_printf.c len_arg.c print_arg.c print_params.c reset.c \
	search_arg.c modify_flags.c

OBJS = $(addprefix $(DIR_OBJ)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(DIR_LIB)
	@cp ./Libft/libft.a ./$(NAME)
	@ar -rcs $(NAME) $(OBJS)
	@echo "\033[0;32m✅️    $(NAME) created."

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(DIR_INC)
	@echo "\033[0;32m✅️    $@ created."

clean:
	@rm -rf $(DIR_OBJ)
	@make clean -C $(DIR_LIB)
	@echo "\033[0;31m🗑️    Deleting object files." 

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(DIR_LIB)
	@echo "\033[0;31m🗑️    Deleting $(NAME) executable." 

re: fclean all
