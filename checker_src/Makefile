NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ../libft/libft.a

FT_PRINTF = ../ft_printf/libftprintf.a

SRC = 	source_files/main.c \
		source_files/check_input.c \
		source_files/linked_list_operations.c \
		source_files/pile_instructions.c \
		source_files/pile_instructions_2.c \
		source_files/pile_a_creation.c \
		source_files/push_swap_utils.c \
		source_files/get_lis_len.c \
		source_files/get_lis_tab.c \
		source_files/push_back_nodes_from_b_to_a.c \
		source_files/get_moves_needed_pile_b.c \
		source_files/get_moves_needed_pile_a.c \
		source_files/execute_instructions.c \
		source_files/pre_sort_pile_a.c \
		source_files/calculate_pivots.c \
		source_files/parse_input.c \
		source_files/checker.c \
		source_files/checker_utils.c \
		GNL/get_next_line.c \
		GNL/get_next_line_utils.c \
		

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -Llibft -lft -Lft_printf -lftprintf
	echo "\033[0;32mCompilation successful\033[0m"

$(LIBFT):
	make -s bonus -C libft 
	make -s -C libft 

$(FT_PRINTF):
	make -s -C ft_printf 

%.o: %.c
	$(CC) $(CFLAGS) -Ilibft -Ift_printf -c $< -o $@

clean:
	rm	-f	$(OBJ) $(OBJ_BONUS)
	make -C libft clean 
	make -C ft_printf clean 

fclean: clean
	rm	-f	$(NAME)
	make -C libft fclean
	make -C ft_printf fclean 

re:	fclean	all		