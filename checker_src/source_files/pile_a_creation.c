/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_a_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:39:04 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/30 06:32:45 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**========================================================================
 *                        convert_input_to_int_tab
 ** malloc used here (int *input_tab) ! beware memory management !
 *========================================================================**/
int	convert_input_to_int_tab(int argc, char **argv, int **input_tab)
{
	int	i;

	if (argc == 2 && argv[1][0] == '\0')
		return (0);
	*input_tab = (int *)malloc(sizeof(int) * (argc - 1));
	if (*input_tab == 0)
		return (0);
	i = 0;
	while (++i <= (argc - 1))
		(*input_tab)[i - 1] = ft_atoi(argv[i]);
	return (1);
}

/**========================================================================
 *                           build_pile_a
 ** malloc used here (t_Data *data) ! beware memory management !
 *========================================================================**/
int	build_pile_a(t_Data **data, int *input_tab, int tab_size)
{
	int		i;
	t_list	*new_node;

	*data = (t_Data *)malloc(sizeof(t_Data));
	if (!*data)
		return (0);
	(*data)->pile_a = NULL;
	(*data)->pile_b = NULL;
	i = 0;
	while (i < tab_size)
	{
		new_node = ft_lstnew(&input_tab[i]);
		if (!new_node)
			return (0);
		ft_lstadd_back(&(*data)->pile_a, new_node);
		i++;
	}
	return (1);
}
