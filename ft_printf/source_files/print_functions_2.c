/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:15:26 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/11 15:01:01 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_null(t_null_output null_value)
{
	if (null_value == zero)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (null_value == nil)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else if (null_value == null)
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (0);
}
