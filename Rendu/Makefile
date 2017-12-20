# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/24 22:08:57 by clcreuso     #+#   ##    ##    #+#        #
#    Updated: 2017/11/24 22:08:57 by clcreuso    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

C_FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

OBJ = $(OBJ1) $(OBJ2)

OBJ1 = $(SRC_PRINTF:.c=.o)

OBJ2 = $(wildcard Libft/*.o)

D_LIB = Libft/

D_INC = Includes/

D_SRC = Ft_printf/

SRC = find_params.c ft_printf.c len_arg.c print_arg.c print_params.c reset.c \
	search_arg.c

SRC_PRINTF = $(addprefix $(D_SRC), $(SRC))		

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(D_LIB)
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[0;32m✅️    $(NAME) created."

./%.o: ./%.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "\033[0;32m✅️    $@ created."

clean:
	@rm -f $(OBJ)
	@make clean -C $(D_LIB)
	@echo "\033[0;31m🗑️    Deleting object files." 

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(D_LIB)
	@echo "\033[0;31m🗑️    Deleting $(NAME) executable." 

re: fclean all