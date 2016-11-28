# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nboute <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/26 20:45:05 by nboute            #+#    #+#              #
#    Updated: 2016/11/28 14:27:42 by nboute           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: make all clean fclean re

NAME = fillit

LIB = -L libft/ -lft

LIBFT = libft/libft.a

CFLAGS = -c -Wall -Wextra -Werror

WFLAGS = -Wall -Wextra -Werror

CC = gcc

C_DIR = srcs/

SRCS = ft_main.c \
	   ft_read.c \
	   ft_solver.c \
	   ft_insert.c \
	   ft_valid_tetra.c

SRC = $(addprefix $(C_DIR), $(SRCS))

OBJ = $(SRCS:.c=.o)

INC = -I includes -I libft/

all : $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(WFLAGS) $^ -o $@ $(LIB)

$(LIBFT):
	make -C libft/

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) $^ $(INC)

clean :
	make clean -C libft/
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIBFT)
	rm -f libft.a
	rm -f $(NAME)

re : fclean all
