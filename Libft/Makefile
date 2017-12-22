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

NAME = libft.a

OBJ = $(SRC:.c=.o)

SRC = ft_lenint_max.c ft_strnew.c ft_atoi.c ft_isprint.c ft_memalloc.c \
	ft_putendl.c ft_strcpy.c ft_strmapi.c ft_putstr.c ft_strnstr.c ft_bzero.c \
	ft_isspace.c ft_memccpy.c ft_putendl_fd.c ft_strdel.c ft_strncat.c \
	ft_putchar.c ft_strrchr.c ft_count_len.c ft_isupper.c ft_memchr.c \
	ft_putnbr_fd.c ft_strdup.c ft_len_base_u.c ft_putnbr.c ft_strsplit.c \
	ft_count_words.c ft_itoa.c ft_memcmp.c ft_putstr_fd.c ft_strequ.c \
	ft_len_base_ll.c ft_putnbr_hd.c ft_strstr.c ft_fillstr.c ft_lenint.c \
	ft_memcpy.c ft_size_int.c ft_striter.c ft_putnbr_base_u.c ft_putnbr_ll.c\
	ft_strsub.c ft_isacii.c ft_lstadd.c ft_memdel.c ft_sqrt.c ft_striteri.c \
	ft_len_base_llu.c ft_str_is_num.c ft_strtrim.c ft_isalnum.c ft_lstdel.c \
	ft_memmove.c ft_strcat.c ft_strjoin.c ft_lenuint_max.c ft_strncmp.c \
	ft_tolower.c ft_isalpha.c ft_lstdelone.c ft_memset.c ft_strchr.c \
	ft_strlcat.c ft_putnbr_base_llu.c ft_strncpy.c ft_toupper.c ft_isdigit.c \
	ft_lstiter.c ft_next_sqrt.c ft_strclr.c ft_strlen.c ft_putnbr_u.c \
	ft_strnequ.c get_next_line.c ft_islower.c ft_lstnew.c ft_putchar_fd.c \
	ft_strcmp.c ft_strmap.c ft_putnbr_llu.c	ft_putnbr_base_hd.c 	

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[0;32m✅️    $(NAME) created."

./%.o: ./%.c
	@$(CC) $(CFLAGS) -o $@ -c $< 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
