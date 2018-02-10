# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 15:52:46 by iporsenn          #+#    #+#              #
#    Updated: 2017/11/22 15:52:48 by iporsenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = ./
SRC_NAME =	ft_atoi.c		\
			ft_bzero.c		\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_itoa.c		\
			ft_lstadd.c		\
			ft_lstdel.c		\
			ft_lstdelone.c	\
			ft_lstiter.c	\
			ft_lstmap.c		\
			ft_lstnew.c		\
			ft_memalloc.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memdel.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_putchar.c	\
			ft_putchar_fd.c	\
			ft_putendl.c	\
			ft_putendl_fd.c	\
			ft_putnbr.c		\
			ft_putnbr_fd.c	\
			ft_putstr.c		\
			ft_putstr_fd.c	\
			ft_strcat.c		\
			ft_strncat.c	\
			ft_strlcat.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strclr.c		\
			ft_strcmp.c		\
			ft_strncmp.c	\
			ft_strcpy.c		\
			ft_strncpy.c	\
			ft_strdel.c		\
			ft_strdup.c		\
			ft_strequ.c		\
			ft_strnequ.c	\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strjoin.c	\
			ft_strlen.c		\
			ft_strmap.c		\
			ft_strmapi.c	\
			ft_strnew.c		\
			ft_strsplit.c	\
			ft_strstr.c		\
			ft_strnstr.c	\
			ft_strsub.c		\
			ft_strtrim.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			join_free.c

SRC =  $(addprefix $(SRC_PATH), $(SRC_NAME))

INCLUDE_PATH =./
INCLUDE_NAME =
INCLUDE = $(addprefix $(INCLUDE_PATH), $(INCLUDE_NAME))

OBJ = $(SRC_NAME:.c=.o)

FLAGS = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME):
	@echo "\033[32mBuilding libft\033[0m"
	@gcc $(SRC) $(INCLUDE) $(FLAGS)
	@ar rc libft.a $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
