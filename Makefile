# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arusso <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 13:46:59 by arusso            #+#    #+#              #
#    Updated: 2017/12/22 11:35:39 by iporsenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./
SRC_NAME =	main.c				\
			get_next_line.c

SRC	= $(addprefix $(SRC_PATH), $(SRC_NAME))

INCLUDE_PATH = ./
INCLUDE_NAME = get_nex_line.h
INCLUDE	= $(addprefix $(INCLUDE_PATH), $(INCLUDE_NAME))

HEADER_PATH = ./libft/
HEADER_NAME = libft.a
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))

OBJ	= $(SRC_NAME:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C libft
	@echo "\033[32mBuilding exe\033[0m"
	@gcc $(FLAGS) $(SRC) $(HEADER) -o $(NAME)


clean :
	@echo "\033[31mCleaning .o\033[0m"
	@make clean -C libft
	@rm -f $(OBJ)

fclean : clean
	@echo "\033[31mCleaning all\033[0m"
	@make fclean -C libft
	@rm -f $(NAME)

re : fclean all
