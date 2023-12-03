/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler_funcs_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:15:25 by dan               #+#    #+#             */
/*   Updated: 2023/11/11 15:01:06 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_x_lowercase(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (!num)
		return (print_null(zero));
	return (ft_put_hex(num, 1, 'x'));
}

int	handle_x_uppercase(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (!num)
		return (print_null(zero));
	return (ft_put_hex(num, 1, 'X'));
}

int	handle_percent(va_list args)
{
	write(1, "%", 1);
	(void)args;
	return (1);
}
