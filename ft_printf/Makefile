# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dan <dan@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 10:40:29 by dsylvain          #+#    #+#              #
#    Updated: 2023/11/29 16:53:24 by dan              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	source_files/ft_printf.c \
		source_files/ft_printf_utils.c \
		source_files/print_functions.c \
		source_files/print_functions_2.c \
		source_files/specifier_handler_funcs.c \
		source_files/specifier_handler_funcs_2.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:_bonus.c=_bonus.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs	$(NAME)	$(OBJ)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm	-f	$(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm	-f	$(NAME) 

re:	fclean	all 

