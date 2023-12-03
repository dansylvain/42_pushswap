# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dan <dan@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 07:30:24 by dsylvain          #+#    #+#              #
#    Updated: 2023/11/29 16:52:55 by dan              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =		ft_atoi.c \
			ft_split.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_isdigit.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_memset.c \
			ft_calloc.c \
			# ft_lstmap_bonus.c\
			# ft_lstlast_bonus.c \
			# ft_bzero.c \
			# ft_isalnum.c \
			# ft_isalpha.c \
			# ft_isascii.c \
			# ft_isprint.c \
			# ft_itoa.c \
			# ft_memchr.c \
			# ft_memcmp.c \
			# ft_memcpy.c \
			# ft_memmove.c \
			# ft_strchr.c \
			# ft_strdup.c \
			# ft_striteri.c \
			# ft_strjoin.c \
			# ft_strlcat.c \
			# ft_strncmp.c \
			# ft_strmapi.c \
			# ft_strnstr.c \
			# ft_strrchr.c \
			# ft_strtrim.c \
			# ft_substr.c \
			# ft_tolower.c \
			# ft_toupper.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:_bonus.c=_bonus.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs	$(NAME)	$(OBJ)

bonus: $(OBJ_BONUS)
	@ar rcs	$(NAME) $(OBJ_BONUS)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm	-f	$(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm	-f	$(NAME) 

re:	fclean	all
