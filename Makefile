# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 14:51:10 by iporsenn          #+#    #+#              #
#    Updated: 2018/01/05 14:51:14 by iporsenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./
SRC_NAME =	main.c				\
			get_next_line.c

SRC	= $(addprefix $(SRC_PATH), $(SRC_NAME))

INCLUDE_PATH = ./
INCLUDE_NAME = get_next_line.h
INCLUDE	= $(addprefix $(INCLUDE_PATH), $(INCLUDE_NAME))

HEADER_PATH = ./libft/
HEADER_NAME = libft.a
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))

OBJ	= $(SRC_NAME:.c=.o)

all : $(NAME)

$(NAME) :
	make -C libft
	gcc $(FLAGS) $(SRC) $(HEADER) -o $(NAME)

clean :
	make clean -C libft
	rm -f $(OBJ)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all
