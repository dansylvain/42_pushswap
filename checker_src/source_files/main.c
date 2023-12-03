/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:36 by dsylvain          #+#    #+#             */
/*   Updated: 2023/12/03 16:32:46 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**========================================================================
 *                             CREDITS
 *  algorythm inspiration: A. Yigit Ogun, https://medium.com/@ayogun
 *  this is my version of his 'turk algorithm', found at
 *  https://medium.com/@ayogun/push-swap-c1f5d2d41e97
 ** display funcs used during developpement below 
 *========================================================================**/
/**========================================================================
  *                           main
  ** check pile_a_is_reversed & !pile_a_is_ordered before LIS calculation
  ** to increase nbr of LIS members (and hence lessen instruction list)
  *========================================================================**/
int	main(int argc, char **argv)
{
	t_Data	*data;
	int		*input_tab;
	int		*lis_tab;

	lis_tab = NULL;
	if (argc == 1)
		return (0);
	argv = parse_input(&argc, argv);
	if (argv == NULL || !argv[1])
		return (error_message(), free_all(NULL, NULL, NULL, argv));
	if (!check_input(argv, argc))
		return (error_message(), free_all(NULL, NULL, NULL, argv));
	if (!convert_input_to_int_tab(argc, argv, &input_tab))
		return (error_message(), free_all(NULL, input_tab, NULL, argv));
	if (!build_pile_a(&data, input_tab, argc - 1))
		return (error_message(), free_all(data, input_tab, NULL, argv));
	run_checker(data, input_tab, lis_tab, argv);
	free_all(data, input_tab, lis_tab, argv);
	return (0);
}

/**========================================================================
 *                          sort_piles
 *========================================================================**/
void	sort_piles(t_Data *data)
{
	int		upper_length;

	data->nodes_to_push_b_to_a = ft_lstsize(data->pile_b);
	while (data->nodes_to_push_b_to_a)
		push_back_nodes_from_b_to_a(data);
	while (data->pile_b)
		instruction_push(data, from_b_to_a);
	upper_length = get_upper_length(data->pile_a);
	while (*data->pile_a->content > *data->pile_a->prev->content)
	{
		if (upper_length < ft_lstsize(data->pile_a) - upper_length)
			instruction_rotate_single(&data->pile_a, ra);
		else
			instruction_rrotate_single(&data->pile_a, rra);
	}
}

/**========================================================================
 *                           get_upper_length
 *========================================================================**/
int	get_upper_length(t_list *pile_a)
{
	t_list	*current;
	int		upper_length;

	upper_length = 0;
	current = pile_a;
	while (1)
	{
		upper_length++;
		if (*current->content > *current->next->content)
			break ;
		current = current->next;
	}
	return (upper_length);
}
// /**========================================================================
//  *                           display_pile
//  *========================================================================**/
// void	display_pile(t_Data *data, t_list *pile)
// {
// 	t_list	*current;

// 	if (!data || !pile)
// 		return ;
// 	current = pile;
// 	while (1)
// 	{
// 		ft_printf("%i\n", *current->content);
// 		current = current->next;
// 		if (current == pile)
// 			break ;
// 	}
// }

// /**========================================================================
//  *                           display_piles
//  *========================================================================**/
// void	display_piles(t_Data *data)
// {
// 	t_list	*current;

// 	ft_printf("---- pile_a ------\n");
// 	current = data->pile_a;
// 	display_pile(data, current);
// 	ft_printf("---- pile_b ------\n");
// 	current = data->pile_b;
// 	display_pile(data, current);
// 	ft_printf("------------------\n");
// }

// /**========================================================================
//  *                           display_lis_tab
//  *========================================================================**/
// void	display_lis_tab(int *lis_tab, int lis_len)
// {
// 	int	i;

// 	if (!lis_tab || !lis_len)
// 		return ;
// 	i = 0;
// 	ft_printf ("LIS: ");
// 	while (i < lis_len)
// 		ft_printf("%i, ", lis_tab[i++]);
// 	ft_printf("\n------------------\n");
// }

// /**========================================================================
//  *                           create_test_piles
//  ** tested
//  *========================================================================**/
// void	create_test_piles(t_Data *data)
// {
// 	int	i;

// 	if (!data)
// 		return ;
// 	i = 0;
// 	while (++i < 6)
// 		ft_transfer_top_node(data, from_a_to_b);
// }
