/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:03:21 by dan               #+#    #+#             */
/*   Updated: 2023/12/03 13:49:32 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_instruction(t_Data *data, int *input_tab,
	int *lis_tab, char **argv)
{
	error_message();
	get_next_line(42);
	exit(free_all(data, input_tab, lis_tab, argv));
}

void	free_next_instruction(char *next_instruction)
{
	if (next_instruction)
	{
		free(next_instruction);
		next_instruction = NULL;
	}
}

void	display_checker_result(t_Data *data)
{
	if (!data->pile_b && ((*data->pile_a->content < *data->pile_a->next->content
				&& *data->pile_a->content < *data->pile_a->prev->content
				&& pile_a_is_ordered(data->pile_a))
			|| ft_lstsize(data->pile_a) == 1))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	check_instruction_loop(t_Data *data, char *next_instruction,
	char *instruction_tab[], int i_tab[])
{
	int	j;
	int	i;
	int	instr_was_found;

	instr_was_found = 0;
	i = 1;
	while (i < 12)
	{
		instr_was_found = 0;
		if (instruction_tab[i] && next_instruction && !strncmp
			(next_instruction, instruction_tab[i], ft_strlen(next_instruction)))
		{
			j = 0;
			while (j < 12)
				i_tab[j++] = nada_zero;
			i_tab[i]++;
			call_instruction_functions(data, i_tab);
			instr_was_found = 1;
			break ;
		}
		i++;
	}
	return (instr_was_found);
}

void	run_checker(t_Data *data, int *input_tab, int *lis_tab, char **argv)
{
	char	*next_instruction;
	char	*instruction_tab[12];
	int		i_tab[11];
	int		instr_was_found;

	next_instruction = "";
	get_instruction_tab(instruction_tab);
	while (1)
	{
		next_instruction = get_next_line(0);
		if (!next_instruction)
			break ;
		instr_was_found = check_instruction_loop(data,
				next_instruction, instruction_tab, i_tab);
		free_next_instruction(next_instruction);
		if (instr_was_found == 0)
			error_instruction(data, input_tab, lis_tab, argv);
	}
	display_checker_result(data);
}
