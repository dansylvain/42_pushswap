/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:40:06 by dsylvain          #+#    #+#             */
/*   Updated: 2023/12/02 18:36:58 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**========================================================================
 *                          instruction_print
 *========================================================================**/
void	instruction_print(enum t_instruction instruction)
{
	char	*instructions[12];

	instructions[nada_zero] = NULL;
	instructions[rr] = "rr";
	instructions[rrr] = "rrr";
	instructions[ra] = "ra";
	instructions[rb] = "rb";
	instructions[rra] = "rra";
	instructions[rrb] = "rrb";
	instructions[sa] = "sa";
	instructions[sb] = "sb";
	instructions[ss] = "ss";
	instructions[pa] = "pa";
	instructions[pb] = "pb";
	ft_printf("%s\n", instructions[instruction]);
}

/**========================================================================
 *                           instruction_swap_single
 *========================================================================**/
void	instruction_swap_single(t_list *pile, enum t_instruction instruction)
{
	if (pile && pile->next)
		ft_swap_node_content(pile, pile->next);
	(void)instruction;
}

/**========================================================================
 *                          instruction_swap_double
 *========================================================================**/
void	instruction_swap_double(t_Data *data)
{
	if (data->pile_a && data->pile_a->next
		&& data->pile_b && data->pile_b->next)
	{
		ft_swap_node_content(data->pile_a, data->pile_a->next);
		ft_swap_node_content(data->pile_b, data->pile_b->next);
	}
}

/**========================================================================
 *                           instruction_push
 *========================================================================**/
void	instruction_push(t_Data *data, enum t_direction direction)
{
	data->nodes_to_push_b_to_a--;
	ft_transfer_top_node(data, direction);
	(void)direction;
}
