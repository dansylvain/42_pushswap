/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:12:19 by dan               #+#    #+#             */
/*   Updated: 2023/12/03 13:13:39 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_instruction_tab(char *instructions[])
{
	instructions[nada_zero] = NULL;
	instructions[rr] = "rr\n";
	instructions[rrr] = "rrr\n";
	instructions[ra] = "ra\n";
	instructions[rb] = "rb\n";
	instructions[rra] = "rra\n";
	instructions[rrb] = "rrb\n";
	instructions[sa] = "sa\n";
	instructions[sb] = "sb\n";
	instructions[ss] = "ss\n";
	instructions[pa] = "pa\n";
	instructions[pb] = "pb\n";
}
