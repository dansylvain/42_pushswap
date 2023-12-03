/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:40:46 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/17 07:15:40 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**==============================================
 *                check_input
 *  checks input validity ON THE STACK.
 *  ! check tab[10000]! 
 *  ! overflows above 10000 ints!
 *=============================================**/
int	check_input(char **argv, int argc)
{
	int	i;
	int	j;
	int	tab[10000];

	if (argc == 2 && argv[1][0] == '\0')
		return (0);
	i = 0;
	while (argv[++i])
		tab[i - 1] = ft_atoi(argv[i]);
	i = 0;
	while (++i < argc)
		if (!is_valid_number(argv[i]))
			return (0);
	i = 0;
	while (i < argc - 1)
	{
		if (tab[i] > INT_MAX || tab[i] < INT_MIN)
			return (0);
		j = -1;
		while (++j < argc - 1)
			if ((tab[i] == tab[j]) && (i != j))
				return (0);
		i++;
	}
	return (1);
}

/**============================================
 *               is_valid_number
 *=============================================**/
int	is_valid_number(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]) && (!ft_issign(number[i])))
			return (0);
		if (ft_issign(number[i]) && ((!(number[i + 1])
					|| ft_issign(number[i + 1]))
				|| (i != 0 && (number[i - 1]))))
			return (0);
		i++;
	}
	if (is_above_max_value(number))
		return (0);
	return (1);
}

/**============================================
 *               is_above_max_value
 *=============================================**/
int	is_above_max_value(const char *nptr)
{
	long int	res;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign *= -1;
	}
	while (ft_isdigit(nptr[i]))
		res = res * 10 + (nptr[i++] - '0');
	if (res * sign > INT_MAX || res * sign < INT_MIN)
		return (1);
	return (0);
}

/**============================================
 *               ft_issign
 *=============================================**/
int	ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}
