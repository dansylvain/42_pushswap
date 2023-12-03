/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:12:11 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/11 15:00:50 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_nbr_str_len(long int n)
{
	int	nbr_str_len;

	nbr_str_len = 0;
	if (n < 0)
	{
		nbr_str_len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		nbr_str_len++;
	}
	nbr_str_len++;
	return (nbr_str_len);
}
