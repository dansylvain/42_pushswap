/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_nodes_from_b_to_a.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 07:06:16 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/30 07:06:19 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**========================================================================
 *                            push_back_nodes_from_b_to_a
 *========================================================================**/
void	push_back_nodes_from_b_to_a(t_Data *data)
{
	t_list	*current;
	int		moves_needed[2];
	int		tmp_moves_needed[2];
	int		lowest_move_cost;
	int		tmp_lowest_move_cost;

	if (!data || !data->pile_b)
		return ;
	psa_initialize_variables(moves_needed, tmp_moves_needed, &lowest_move_cost);
	current = data->pile_b;
	while (1)
	{
		tmp_moves_needed[0] = 0;
		tmp_moves_needed[1] = 0;
		get_moves_needed_pile_b(data, current, tmp_moves_needed,
			&tmp_lowest_move_cost);
		get_moves_needed_pile_a(data, current, tmp_moves_needed,
			&tmp_lowest_move_cost);
		update_variables(&lowest_move_cost, &tmp_lowest_move_cost,
			moves_needed, tmp_moves_needed);
		if (lowest_move_cost == 0 || current->next == data->pile_b)
			break ;
		current = current->next;
	}
	execute_instructions(data, moves_needed);
}

/**========================================================================
 *                          psa_initialize_variables
 *========================================================================**/
void	psa_initialize_variables(int moves_needed[], int tmp_moves_needed[],
		int *lowest_move_cost)
{
	moves_needed[0] = 0;
	moves_needed[1] = 0;
	tmp_moves_needed[0] = 0;
	tmp_moves_needed[1] = 0;
	*lowest_move_cost = INT_MAX;
}

/**========================================================================
 *                           update_variables
 *========================================================================**/
void	update_variables(int *lowest_move_cost, int *tmp_lowest_move_cost,
		int moves_needed[], int tmp_moves_needed[])
{
	if (*tmp_lowest_move_cost < *lowest_move_cost)
	{
		*lowest_move_cost = *tmp_lowest_move_cost;
		moves_needed[0] = tmp_moves_needed[0];
		moves_needed[1] = tmp_moves_needed[1];
	}
	tmp_moves_needed[0] = 0;
	tmp_moves_needed[1] = 0;
	*tmp_lowest_move_cost = INT_MAX;
}
