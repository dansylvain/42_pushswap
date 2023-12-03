/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 07:14:43 by dsylvain          #+#    #+#             */
/*   Updated: 2023/12/02 06:26:51 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**============================================
 *               get_lis_len
 *=============================================**/
int	get_lis_len(t_list *pile)
{
	t_list	*current;
	int		lis_length;
	int		tmp;
	int		chicken_have_no_teeth;

	if (!pile)
		return (0);
	chicken_have_no_teeth = 42;
	lis_length = 1;
	current = pile;
	while (chicken_have_no_teeth)
	{
		tmp = get_lis_length_binary_search(current);
		if (tmp > lis_length)
			lis_length = tmp;
		current = current->next;
		if (current == pile)
			break ;
	}
	return (lis_length);
}

/**============================================
 *               get_lis_length_binary_search
 *=============================================**/
int	get_lis_length_binary_search(t_list *node)
{
	int			*lis;
	long int	tabs[2][5000];
	int			i;
	int			node_size;

	i = 0;
	lis = &i;
	node_size = ft_lstsize(node);
	gll_initialize_tabs(tabs, node, 5000);
	fill_tab_2(tabs, node_size);
	calculate_lis_from_tab_2(tabs[1], lis, node_size);
	return (*lis);
	(void)tabs;
}

/**============================================
 *               initialize_tabs
 *=============================================**/
void	gll_initialize_tabs(long int tab[][5000], t_list *node, int size)
{
	t_list	*current;
	int		i;

	current = node;
	i = 0;
	while (1)
	{
		tab[0][i++] = *current->content;
		current = current->next;
		if (current == node)
			break ;
	}
	i = 0;
	while (i < size)
		tab[1][i++] = LONG_MAX;
}

/**============================================
 *               fill_tab_2
 *=============================================**/
void	fill_tab_2(long int tabs[][5000], int node_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < node_size)
	{
		j = 0;
		while (j < node_size)
		{
			if (tabs[1][j] > tabs[0][i])
			{
				tabs[1][j] = tabs[0][i];
				break ;
			}
			j++;
		}
		i++;
	}
}

/**============================================
 *               calculate_lis_from_tab_2
 *=============================================**/
void	calculate_lis_from_tab_2(long int tab_2[], int *lis, int node_size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < node_size)
	{
		if (tab_2[j] != LONG_MAX)
			i++;
		j++;
	}
	if (i > *lis)
		*lis = i;
}
