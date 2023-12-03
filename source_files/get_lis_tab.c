/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:42:04 by dsylvain          #+#    #+#             */
/*   Updated: 2023/12/02 12:53:00 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**========================================================================
 *                           get_lis_tab
 **	the dynamic programming algorithm is used to get the 
 ** "longest increasing Subsequence" (lis)
 ** these operations are done on the stack
 ** resulting integers tab saved on the heap (lis_tab)
 *! no verifs are made to check wether at least 5000 elements!!!
 *========================================================================**/

int	get_lis_tab(t_list *pile_a, int **lis_tab, t_Data *data)
{
	t_list		*current;
	int			dp_tab[3][5000];
	int			lis_len;

	if (!pile_a)
		return (line_saver(lis_tab), -1);
	lis_len = get_lis_len(pile_a);
	data->lis_len = lis_len;
	*lis_tab = (int *)ft_calloc(lis_len + 1, sizeof(long int));
	if (!*lis_tab)
		return (0);
	current = pile_a;
	while (1)
	{
		current = current->next;
		glt_initialize_tabs(current, dp_tab);
		if (dp_search_of_lis(dp_tab, lis_len))
		{
			fill_lis_tab(*lis_tab, dp_tab, lis_len, ft_lstsize(pile_a));
			break ;
		}
		if (current == pile_a)
			break ;
	}
	return (1);
}

/**========================================================================
 *                           line_saver
 ** norminated limitations related function
 *========================================================================**/
void	line_saver(int **lis_tab)
{
	*lis_tab = NULL;
}

/**========================================================================
 *                           glt_initialize_tabs
 *========================================================================**/
void	glt_initialize_tabs(t_list *node, int dp_tab[][5000])
{
	t_list	*current;
	int		i;

	i = 0;
	current = node;
	while (i < 5000)
	{
		dp_tab[1][i] = 1;
		dp_tab[2][i] = -1;
		if (current)
			dp_tab[0][i] = *current->content;
		else
			dp_tab[0][i] = INT_MAX;
		current = current->next;
		i++;
		if (current == node)
			break ;
	}
	while (i < 5000)
	{
		dp_tab[1][i] = 0;
		dp_tab[2][i] = -1;
		dp_tab[0][i] = INT_MAX;
		i++;
	}
}

/**========================================================================
 *                           dp_search_of_lis
 ** "dp" stands for 'dynamic programming',
 ** the name of this algorithm...
 ** + var lis_i stands for 'LIS indexes' :)
 *========================================================================**/
int	dp_search_of_lis(int dp_tab[][5000], int lis_len)
{
	int	i[3];

	i[0] = 1;
	i[2] = 0;
	while (dp_tab[1][i[0]] != 0)
	{
		i[1] = 0;
		while (i[1] < i[0])
		{
			if (dp_tab[0][i[0]] > dp_tab[0][i[1]])
			{
				i[2] = dp_tab[1][i[1]] + 1;
				if (i[2] > dp_tab[1][i[0]])
				{
					dp_tab[1][i[0]] = i[2];
					dp_tab[2][i[0]] = i[1];
				}
				if (i[2] == lis_len)
					return (1);
			}
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}

/**========================================================================
 *                           fill_lis_tab
 *========================================================================**/
void	fill_lis_tab(int *lis_tab, int dp_tab[][5000], int lis, int size)
{
	int	i;
	int	lis_index;

	lis_index = -1;
	i = size - 1;
	while (dp_tab[1][i] != lis)
		i--;
	lis_index = i;
	i = lis - 1;
	while (lis_index != -1)
	{
		lis_tab[i] = dp_tab[0][lis_index];
		lis_index = dp_tab[2][lis_index];
		i--;
	}
	lis_tab[lis] = INT_MAX;
}
