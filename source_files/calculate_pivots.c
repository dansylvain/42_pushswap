/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_pivots.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:35:31 by dan               #+#    #+#             */
/*   Updated: 2023/11/24 19:03:42 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**========================================================================
 *                          calculate_pivots
 *========================================================================**/
void	calculate_pivots(t_Data *data, int *input_tab)
{
	int	i;
	int	size;
	int	tmp_tab[5000];

	i = 0;
	size = ft_lstsize(data->pile_a);
	while (i < size)
	{
		tmp_tab[i] = input_tab[i];
		i++;
	}
	calculate_pivot_loop(size, tmp_tab);
	fill_pivot_tab(data, tmp_tab, size);
}

/**========================================================================
 *                           calculate_pivot_loop
 *========================================================================**/
void	calculate_pivot_loop(int size, int tmp_tab[])
{
	int	swap_occurred;
	int	end;
	int	i;

	end = size - 1;
	while (end > 0)
	{
		i = 0;
		swap_occurred = 0;
		while (i < end)
		{
			if (tmp_tab[i] > tmp_tab[i + 1])
			{
				ft_swap(&tmp_tab[i], &tmp_tab[i + 1]);
				swap_occurred = 1;
			}
			i++;
		}
		if (swap_occurred == 0)
			break ;
	}
}

/**========================================================================
 *                           fill_pivot_tab
 ** pivots calculated for further optimization
 ** NOT ALL USED IN BASE VERSION (only pivot used : data->pivot_tab[0])
 *========================================================================**/
void	fill_pivot_tab(t_Data *data, int tmp_tab[], int size)
{
	data->pivot_tab[0] = tmp_tab[size / 2];
	data->pivot_tab[1] = tmp_tab[size / 4];
	data->pivot_tab[2] = tmp_tab[size * 3 / 4];
	data->pivot_tab[3] = tmp_tab[size / 8];
	data->pivot_tab[4] = tmp_tab[size * 3 / 8];
	data->pivot_tab[5] = tmp_tab[size * 5 / 8];
	data->pivot_tab[6] = tmp_tab[size * 7 / 8];
}

/**========================================================================
 *                           ft_swap
 *========================================================================**/
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
