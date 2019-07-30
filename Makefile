# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niboute <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 18:34:41 by niboute           #+#    #+#              #
#    Updated: 2019/07/30 15:01:26 by niboute          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

SRC= solve.c \
	 parse.c \
	 utils.c \
	 main.c

SRCDIR= src/

SRCS= $(addprefix $(SRCDIR), $(SRC))

OBJ= $(SRCS:.c=.o)

LIBFT= libft/libft.a

FT= -L ./libft/ -lft

CC= gcc

CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(FT)

$(LIBFT):
	make -C libft/

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: clean fclean all

.PHONY: all clean fclean re
