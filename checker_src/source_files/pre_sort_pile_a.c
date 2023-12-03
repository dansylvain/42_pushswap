/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_pile_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:19:15 by dan               #+#    #+#             */
/*   Updated: 2023/12/02 08:33:03 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/**========================================================================
 *                             OPTMIZATION
 **  This file handles optimisation in pre-sorting pushes between pile_a
 **  and pile_b. Not much is done for now, but further presorting steps could
 **  be implemented to optimize in case of larger input.
 **  Pivots are already calculated and stored in data->pivot_tab[7].
 **  in both cases below LIS is used for opti (longest increasing subsequence)
 *========================================================================**/
/**========================================================================
 *                           pre_sort_pile_a
 ** 50 was chosen here arbitrarily. This passed the tests.
 ** calculations could be done to determine optimal value.
 ** in actual state (02/12/23) pre-sorting occurs only above 50 ints input.
 *========================================================================**/
void	pre_sort_pile_a(t_Data *data, int *lis_tab)
{
	if (ft_lstsize(data->pile_a) <= 50)
	{
		while (!pile_a_is_ordered(data->pile_a))
		{
			if (!is_in_lis_tab(data->pile_a, lis_tab))
				instruction_push(data, from_a_to_b);
			else
				instruction_rotate_single(&data->pile_a, ra);
		}
		return ;
	}
	else
		pre_sort_over_fifty_ints(data, lis_tab);
}

/**========================================================================
 *                          pre_sort_over_fifty_ints 
 *========================================================================**/
void	pre_sort_over_fifty_ints(t_Data *data, int *lis_tab)
{
	int	i;

	i = ft_lstsize(data->pile_a);
	if (!pile_a_is_ordered(data->pile_a))
	{
		while (i > 0)
		{
			if (data && data->pile_a && is_in_lis_tab(data->pile_a, lis_tab))
				instruction_rotate_single(&data->pile_a, ra);
			else if (data && data->pile_a && *data->pile_a->content
				> data->pivot_tab[0])
			{
				instruction_push(data, from_a_to_b);
			}
			else
			{
				instruction_push(data, from_a_to_b);
				instruction_rotate_single(&data->pile_b, rb);
			}
			i--;
		}
	}
}

/**========================================================================
 *                           is_in_lis_tab
 *========================================================================**/
int	is_in_lis_tab(t_list *node, int *lis_tab)
{
	int	i;

	i = 0;
	while (lis_tab[i] != INT_MAX)
	{
		if (node && lis_tab[i] == *node->content)
			return (1);
		i++;
	}
	(void)node;
	return (0);
}

/**========================================================================
 *                           pile_a_is_ordered
 *========================================================================**/
int	pile_a_is_ordered(t_list *pile)
{
	t_list	*current;
	int		found_junction;

	found_junction = 0;
	current = pile;
	if (current == current->next)
		return (1);
	while (1)
	{
		if (*current->content > *current->next->content)
			found_junction += 1;
		current = current->next;
		if (current == pile)
			break ;
	}
	if (found_junction == 1)
		return (1);
	else
		return (0);
}

/**========================================================================
 *                           pile_a_is_reversed
 *========================================================================**/
int	pile_a_is_reversed(t_list *pile)
{
	t_list	*current;
	int		found_junction;

	found_junction = 0;
	current = pile;
	if (current == current->next)
		return (0);
	while (1)
	{
		if (*current->content < *current->next->content)
			found_junction += 1;
		current = current->next;
		if (current == pile)
			break ;
	}
	if (found_junction == 1)
		return (1);
	else
		return (0);
}
