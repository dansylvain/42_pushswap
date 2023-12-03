/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves_needed_pile_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:46:04 by dan               #+#    #+#             */
/*   Updated: 2023/11/30 06:55:02 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**========================================================================
 *                       get_moves_needed_pile_a
 *! this function only accepts valid parameters. Check before calling!!! 
 ** tmp_lowest_move_cost set and reset here to gain space
 ** in function push_back_nodes_from_b_to_a()
 *! func formerly written for pile_b. !!beware changes!!
 *========================================================================**/
void	get_moves_needed_pile_a(t_Data *data, t_list *node,
		int tmp_moves_needed[], int *tmp_lowest_move_cost)
{
	if (!data || !node || !data->pile_a)
		return ;
	pile_a_move_nbr_ftwards(data, node, tmp_moves_needed, tmp_lowest_move_cost);
	pile_a_move_nbr_bkward(data, node, tmp_moves_needed, tmp_lowest_move_cost);
	*tmp_lowest_move_cost = 0;
	if (tmp_moves_needed[0] > 0)
		*tmp_lowest_move_cost += tmp_moves_needed[0];
	else
		*tmp_lowest_move_cost -= tmp_moves_needed[0];
	if (tmp_moves_needed[1] > 0)
		*tmp_lowest_move_cost += tmp_moves_needed[1];
	else
		*tmp_lowest_move_cost -= tmp_moves_needed[1];
}

/**========================================================================
 *                         pile_a_move_nbr_ftwards
 * ! tmp_moves_needed[1] value's sign inverted to match pile_a's
 *========================================================================**/
void	pile_a_move_nbr_ftwards(t_Data *data, t_list *node,
		int tmp_moves_needed[], int *tmp_lowest_move_cost)
{
	t_list	*current;
	int		i;
	int		node_value;

	i = 0;
	current = data->pile_a;
	node_value = *node->content;
	check_only_one_node_in_pile_b(data, tmp_moves_needed, tmp_lowest_move_cost);
	while (1)
	{
		if (breaking_condition (current, node_value))
			break ;
		i++;
		current = current->next;
		if (current == data->pile_a)
			break ;
	}
	if (i < *tmp_lowest_move_cost)
	{
		tmp_moves_needed[1] = -i;
		*tmp_lowest_move_cost = i;
	}
}

/**========================================================================
 *                        pile_a_move_nbr_bkward
 * ! tmp_moves_needed[1] value's sign inverted to match pile_a's
 *========================================================================**/
void	pile_a_move_nbr_bkward(t_Data *data, t_list *node,
		int tmp_moves_needed[], int *tmp_lowest_move_cost)
{
	t_list	*current;
	int		i;
	int		node_value;

	node_value = *node->content;
	i = 0;
	current = data->pile_a;
	while (1)
	{
		if (breaking_condition(current, node_value))
			break ;
		i--;
		current = current->prev;
		if (current == data->pile_a)
			break ;
	}
	if (-i < *tmp_lowest_move_cost)
	{
		tmp_moves_needed[1] = -i;
		*tmp_lowest_move_cost = -i;
	}
}

/**========================================================================
 *                       check_only_one_node_in_pile_b
 *========================================================================**/
void	check_only_one_node_in_pile_b(t_Data *data, int tmp_moves_needed[],
		int *tmp_lowest_move_cost)
{
	if ((!data->pile_a || (data->pile_a->next == data->pile_a)))
	{
		tmp_moves_needed[1] = 0;
		*tmp_lowest_move_cost = 0;
	}
}

/**========================================================================
 *                          breaking_condition
 *========================================================================**/
int	breaking_condition(t_list *current, int node_value)
{
	if ((*current->content < *current->prev->content && *current->content
			< *current->next->content) && ((*current->content < node_value
				&& *current->prev->content < node_value) || (*current->content
				> node_value && *current->prev->content > node_value)))
		return (1);
	if ((node_value < *current->content && node_value
			> *current->prev->content))
		return (1);
	return (0);
}
