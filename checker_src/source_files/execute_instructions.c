/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 05:56:28 by dsylvain          #+#    #+#             */
/*   Updated: 2023/12/02 17:56:44 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**========================================================================
 *                           execute_instructions
 *========================================================================**/
void	execute_instructions(t_Data *data, int moves_needed[])
{
	int	i_tab[7];
	int	i;

	i = nada_zero;
	while (i < 7)
		i_tab[i++] = nada_zero;
	if (moves_needed[0] > 0 && moves_needed[1] > 0)
		i_tab[rrr] = min_val(moves_needed[0], moves_needed[1]);
	else if (moves_needed[0] < 0 && moves_needed[1] < 0)
		i_tab[rr] = min_val(abs_val(moves_needed[0]), abs_val(moves_needed[1]));
	if (moves_needed[0] < 0)
		i_tab[rb] = abs_val(moves_needed[0]) - i_tab[rr];
	else if (moves_needed[0] > 0)
		i_tab[rrb] = moves_needed[0] - i_tab[rrr];
	if (moves_needed[1] < 0)
		i_tab[ra] = abs_val(moves_needed[1]) - i_tab[rr];
	else if (moves_needed[1] > 0)
		i_tab[rra] = moves_needed[1] - i_tab[rrr];
	call_instruction_functions(data, i_tab);
}

/**========================================================================
 *                      call_instruction_functions
 *========================================================================**/
void	call_instruction_functions(t_Data *data, int i_tab[])
{
	while (--i_tab[rr] >= 0)
		instruction_rotate_double(data);
	while (--i_tab[rrr] >= 0)
		instruction_rrotate_double(data);
	while (--i_tab[ra] >= 0)
		instruction_rotate_single(&data->pile_a, ra);
	while (--i_tab[rb] >= 0)
		instruction_rotate_single(&data->pile_b, rb);
	while (--i_tab[rra] >= 0)
		instruction_rrotate_single(&data->pile_a, rra);
	while (--i_tab[rrb] >= 0)
		instruction_rrotate_single(&data->pile_b, rrb);
	while (--i_tab[sa] >= 0)
		instruction_swap_single(data->pile_a, sa);
	while (--i_tab[sb] >= 0)
		instruction_swap_single(data->pile_b, sb);
	while (--i_tab[pa] >= 0)
		instruction_push(data, from_b_to_a);
	while (--i_tab[pb] >= 0)
		instruction_push(data, from_a_to_b);
}

/**========================================================================
 *                           min_val
 *========================================================================**/
int	min_val(int val_1, int val_2)
{
	if (val_1 <= val_2)
		return (val_1);
	else
		return (val_2);
}

/**========================================================================
 *                           max_value
 *========================================================================**/
int	max_value(int val_1, int val_2)
{
	if (val_1 >= val_2)
		return (val_1);
	else
		return (val_2);
}

/**========================================================================
 *                           abs_val
 *========================================================================**/
int	abs_val(int val)
{
	if (val <= 0)
		return (-val);
	else
		return (val);
}
