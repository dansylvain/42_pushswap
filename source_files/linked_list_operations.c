/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:58:19 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/29 17:17:13 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**============================================
 *               ft_transfer_top_node
 *=============================================**/
void	ft_transfer_top_node(t_Data *data, enum t_direction direction)
{
	t_list	*tmp;

	if (direction == from_a_to_b && data->pile_a)
	{
		tmp = data->pile_a;
		ft_detach_top_node(&data->pile_a);
		ft_lstadd_front(&data->pile_b, tmp);
	}
	else if (direction == from_b_to_a && data->pile_b)
	{
		tmp = data->pile_b;
		ft_detach_top_node(&data->pile_b);
		ft_lstadd_front(&data->pile_a, tmp);
	}
}

/**============================================
 *               ft_detach_top_node
 *=============================================**/
void	ft_detach_top_node(t_list	**pile)
{
	if (!pile || !*pile)
		return ;
	if ((*pile)->next == *pile)
		*pile = NULL;
	else
	{
		(*pile)->prev->next = (*pile)->next;
		(*pile)->next->prev = (*pile)->prev;
		*pile = (*pile)->next;
	}
}

/**============================================
 *               ft_swap_node_content
 *=============================================**/
void	ft_swap_node_content(t_list *node1, t_list *node2)
{
	int	*tmp;

	tmp = node1->content;
	node1->content = node2->content;
	node2->content = tmp;
}
