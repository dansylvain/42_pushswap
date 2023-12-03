/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:46:34 by dsylvain          #+#    #+#             */
/*   Updated: 2023/12/03 17:07:28 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "GNL/get_next_line.h"
# include <unistd.h>  // Pour read et write
# include <stdlib.h>  // Pour malloc, free, et exit
# include <limits.h>

/**============================================
 *               ENUMS - STRUCTS
 *=============================================**/
typedef struct t_Data
{
	t_list	*pile_a;
	t_list	*pile_b;
	int		nodes_to_push_b_to_a;
	int		lis_len;
	int		pivot_tab[7];
}	t_Data;

typedef enum t_direction
{
	from_a_to_b,
	from_b_to_a
}	t_direction;

typedef enum t_instruction
{
	nada_zero,
	rr,
	rrr,
	ra,
	rb,
	rra,
	rrb,
	sa,
	sb,
	ss,
	pa,
	pb
}	t_instruction;

/**============================================
 *               PROTOTYPES
 *=============================================**/
/*   execute_instructions.c                             :+:      :+:    :+:   */
void	call_instruction_functions(t_Data *data, int i_tab[]);
/*   execute_instructions_utils.c                       :+:      :+:    :+:   */
int		min_val(int val_1, int val_2);
int		max_value(int val_1, int val_2);
int		abs_val(int val);
/*   get_lis_len.c                                  :+:      :+:    :+:   */
int		get_lis_len(t_list *pile);
int		get_lis_length_binary_search(t_list *node);
void	gll_initialize_tabs(long int tabs[][5000], t_list *node, int size);
void	fill_tab_2(long int tabs[][5000], int node_size);
void	calculate_lis_from_tab_2(long int tab_2[], int *lis, int node_size);
/*   get_lis_tab.c                                      :+:      :+:    :+:   */
int		get_lis_tab(t_list *pile_a, int **lis_tab, t_Data *data);
void	get_lis_tab_loop(t_list *current, int dp_tab[][5000],
			int **lis_tab, t_Data *data);
void	glt_initialize_tabs(t_list *pile_a, int dp_tab[][5000]);
int		dp_search_of_lis(int dp_tab[][5000], int lis);
void	fill_lis_tab(int *lis_tab, int dp_tab[][5000], int lis, int size);
void	line_saver(int **lis_tab);
/*   get_moves_needed_pile_b.c                          :+:      :+:    :+:   */
void	get_moves_needed_pile_b(t_Data *data, t_list *node,
			int tmp_moves_needed[], int *tmp_lowest_move_cost);
void	pile_b_move_nbr_ftwards(t_Data *data, t_list *node,
			int tmp_moves_needed[], int *tmp_lowest_move_cost);
void	pile_b_move_nbr_bkward(t_Data *data, t_list *node,
			int tmp_moves_needed[], int *tmp_lowest_move_cost);
/*   get_moves_needed_pile_a.c                          :+:      :+:    :+:   */
void	get_moves_needed_pile_a(t_Data *data, t_list *node,
			int tmp_moves_needed[], int *tmp_lowest_move_cost);
void	pile_a_move_nbr_ftwards(t_Data *data, t_list *node,
			int tmp_moves_needed[], int *tmp_lowest_move_cost);
void	pile_a_move_nbr_bkward(t_Data *data, t_list *node,
			int tmp_moves_needed[], int *tmp_lowest_move_cost);
void	check_only_one_node_in_pile_b(t_Data *data, int tmp_moves_needed[],
			int *tmp_lowest_move_cost);
int		breaking_condition(t_list *current, int node_value);
/*   check_input.c                       :+:      :+:    :+:   */
int		check_input(char **argv, int argc);
int		is_valid_number(char *number);
int		is_above_max_value(const char *nptr);
int		ft_issign(char c);
void	error_instruction(t_Data *data, int *input_tab,
			int *lis_tab, char **argv);
void	free_next_instruction(char *next_instruction);
void	display_checker_result(t_Data *data);
int		check_instruction_loop(t_Data *data, char *next_instruction,
			char *instruction_tab[], int i_tab[]);
void	get_instruction_tab(char *instructions[]);
void	run_checker(t_Data *data, int *input_tab, int *lis_tab, char **argv);
/*   linked_list_operations.c                           :+:      :+:    :+:   */
void	ft_transfer_top_node(t_Data *data, enum t_direction direction);
void	ft_detach_top_node(t_list	**pile);
void	ft_swap_node_content(t_list *node1, t_list *node2);
/*   main.c                                             :+:      :+:    :+:   */
void	get_instruction_tab(char *instructions[]);
int		main(int argc, char **argv);
void	sort_piles(t_Data *data);
int		get_upper_length(t_list *pile_a);
void	display_pile(t_Data *data, t_list *pile);
void	display_piles(t_Data *data);
void	display_lis_tab(int *lis_tab, int lis_len);
void	create_test_piles(t_Data *data);
/*   parse_input.c                                      :+:      :+:    :+:   */
char	**parse_input(int *argc, char **argv);
char	**build_new_argv(int new_argc, char tmp_argv[][11]);
int		is_string(char *str);
void	parse_string(char *str, char tmp_argv[][11], int *new_argc);
void	initialize_tmp_argv(char tmp_argv[][11]);
/*   pile_a_creation.c  */
int		convert_input_to_int_tab(int argc, char **argv, int **input_tab);
int		build_pile_a(t_Data **data, int *input_tab, int tab_size);
/*   pile_instructions_2.c */
void	instruction_rotate_single(t_list **pile, enum t_instruction instr);
void	instruction_rrotate_single(t_list **pile, enum t_instruction instr);
void	instruction_rotate_double(t_Data *data);
void	instruction_rrotate_double(t_Data *data);
/*   pile_instructions.c                                :+:      :+:    :+:   */
void	instruction_print(enum t_instruction instruction);
void	instruction_swap_single(t_list *pile, enum t_instruction instruction);
void	instruction_swap_double(t_Data *data);
void	instruction_push(t_Data *data, enum t_direction direction);
/*   calculate_pivots.c                            :+:      :+:    :+:   */
void	calculate_pivots(t_Data *data, int *input_tab);
void	calculate_pivot_loop(int size, int tmp_tab[]);
void	fill_pivot_tab(t_Data *data, int tmp_tab[], int size);
void	ft_swap(int *a, int *b);
/*   push_back_nodes_from_b_to_a.c                    :+:      :+:    :+:   */
int		is_in_lis_tab(t_list *node, int *lis_tab);
void	push_back_nodes_from_b_to_a(t_Data *data);
void	psa_initialize_variables(int moves_needed[], int tmp_moves_needed[],
			int *lowest_move_cost);
void	update_variables(int *lowest_move_cost, int *tmp_lowest_move_cost,
			int moves_needed[], int tmp_moves_needed[]);
void	convert_moves_needed_to_instruction_enum_list(int moves_needed[]);
void	execute_instructions(t_Data *data, int moves_needed[]);
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
int		error_message(void);
void	del(void *nil);
int		free_all(t_Data *data, int *input_tab, int *lis_tab, char **argv);
/*   pre_sort_pile_a.c                                  :+:      :+:    :+:   */
int		pile_a_is_reversed(t_list *pile);
void	pre_sort_pile_a(t_Data *data, int *lis_tab);
void	pre_sort_over_fifty_ints(t_Data *data, int *lis_tab);
/*   push_back_pile_b.c                                 :+:      :+:    :+:   */
void	push_back_pile_b(t_Data *data);
int		pile_a_is_ready(t_Data **data);
int		pile_a_is_ordered(t_list *pile);
void	order_pile_a(t_list **pile_a);
/*   main.c                                  :+:      :+:    :+:   */
void	display_lis_tab(int *lis_tab, int lis_len);
void	display_pile(t_Data *data, t_list *pile);
void	display_piles(t_Data *data);
void	create_test_piles(t_Data *data);
int		main(int argc, char **argv);

#endif