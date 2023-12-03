/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves_needed_pile_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:11:13 by dan               #+#    #+#             */
/*   Updated: 2023/11/30 06:55:03 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**========================================================================
 *                           get_moves_needed_pile_b
 *! this function only accepts valid parameters. Check before calling!!! 
 ** tmp_lowest_move_cost set and reset here to gain space
 ** in function push_back_nodes_from_b_to_a()
 *! func formerly written for pile_a. !!beware changes!!
 *========================================================================**/
void	get_moves_needed_pile_b(t_Data *data, t_list *node,
		int tmp_moves_needed[], int *tmp_lowest_move_cost)
{
	*tmp_lowest_move_cost = INT_MAX;
	if (!data || !node || !data->pile_b)
		return ;
	pile_b_move_nbr_ftwards(data, node, tmp_moves_needed, tmp_lowest_move_cost);
	pile_b_move_nbr_bkward(data, node, tmp_moves_needed, tmp_lowest_move_cost);
	if (data->pile_a && data->pile_a != data->pile_a->next)
		*tmp_lowest_move_cost = INT_MAX;
}

/**========================================================================
 *                        pile_b_get_move_nbr_frontwards
 *========================================================================**/
void	pile_b_move_nbr_ftwards(t_Data *data, t_list *node,
		int tmp_moves_needed[], int *tmp_lowest_move_cost)
{
	t_list	*current;
	int		i;

	i = 0;
	current = node;
	while (1)
	{
		if (current == data->pile_b)
			break ;
		i++;
		current = current->next;
	}
	if (i < *tmp_lowest_move_cost)
	{
		tmp_moves_needed[0] = i;
		*tmp_lowest_move_cost = i;
	}
}

/**========================================================================
 *                        pile_b_move_nbr_bkward
 *========================================================================**/
void	pile_b_move_nbr_bkward(t_Data *data, t_list *node,
		int tmp_moves_needed[], int *tmp_lowest_move_cost)
{
	t_list	*current;
	int		i;

	i = 0;
	current = node;
	while (1)
	{
		if (current == data->pile_b)
			break ;
		i--;
		current = current->prev;
	}
	if (-i < *tmp_lowest_move_cost)
	{
		tmp_moves_needed[0] = i;
		*tmp_lowest_move_cost = -i;
	}
}
