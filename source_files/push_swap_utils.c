/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:41:08 by dsylvain          #+#    #+#             */
/*   Updated: 2023/12/03 16:39:21 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**============================================
 *               error_message
 *=============================================**/
int	error_message(void)
{
	ft_printf("Error\n");
	return (2);
}

/**============================================
 *               del
 ** used by libft funcs - no use for this project
 *=============================================**/
void	del(void *nil)
{
	(void)nil;
}

/**============================================
 *               free_all
 *=============================================**/
int	free_all(t_Data *data, int *input_tab, int *lis_tab, char **argv)
{
	int	i;

	if (data)
	{
		if (data->pile_a)
			ft_lstclear(&data->pile_a);
		if (data->pile_b)
			ft_lstclear(&data->pile_b);
		free(data);
	}
	i = 0;
	if (argv)
	{
		while (argv[i])
		{
			free (argv[i]);
			i++;
		}
		free(argv);
	}
	if (input_tab)
		free(input_tab);
	if (lis_tab)
		free(lis_tab);
	return (255);
}
