# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmthimun <hmthimun@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 18:34:52 by hmthimun          #+#    #+#              #
#    Updated: 2017/12/11 12:44:11 by hmthimun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

SRC = fdf.c get_co_ordinates.c get_pixels.c key_function.c \
		print_line.c ft_abs.c free_2d.c\

OBJ = $(SRC:.c=.o)

HEADER = ./fdf.h

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft

ARFLAGS	= ar rcs

TEST = @echo -e "\e[1;34mBuilding $<\e[0m"

all: $(NAME)

$(NAME):
	@echo "Compiling libft"
	@make -C $(LIBFT) all
	@echo "Compiling fdf files"
	@$(CC) $(CFLAGS) -I $(HEADER) -c $(SRC)
	@$(ARFLAGS) $(NAME) $(OBJ)

clean:
	@echo "Cleaning All files"
	@make -C $(LIBFT) clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "F Cleaning All files"
	@make -C $(LIBFT) fclean
	@/bin/rm -f $(NAME)

re: fclean all
