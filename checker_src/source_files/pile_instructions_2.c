/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_instructions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:43:39 by dsylvain          #+#    #+#             */
/*   Updated: 2023/12/02 18:37:35 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**========================================================================
 *                           instruction_rotate_single
 ** enum 'instruction' changed to 'instr' for
 ** norminette line length limitation
 *========================================================================**/
void	instruction_rotate_single(t_list **pile, enum t_instruction instr)
{
	if (!*pile || !(*pile)->next)
		return ;
	*pile = (*pile)->next;
	(void)instr;
}

/**========================================================================
 *                           instruction_rrotate_single
 ** enum 'instruction' changed to 'instr' for
 ** norminette line length limitation
 *========================================================================**/
void	instruction_rrotate_single(t_list **pile, enum t_instruction instr)
{
	if (!*pile || !(*pile)->prev)
		return ;
	*pile = (*pile)->prev;
	(void)instr;
}

/**========================================================================
 *                         instruction_rotate_double
 *========================================================================**/
void	instruction_rotate_double(t_Data *data)
{
	instruction_rotate_single(&data->pile_a, 0);
	instruction_rotate_single(&data->pile_b, 0);
}

/**========================================================================
 *                          instruction_rrotate_double
 *========================================================================**/
void	instruction_rrotate_double(t_Data *data)
{
	instruction_rrotate_single(&data->pile_a, 0);
	instruction_rrotate_single(&data->pile_b, 0);
}
