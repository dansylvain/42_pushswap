/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler_funcs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:56:14 by dan               #+#    #+#             */
/*   Updated: 2023/11/11 15:01:12 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (ft_putchar_fd(c, 1));
}

int	handle_s(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (print_null(null));
	return (ft_putstr_fd(str, 1));
}

int	handle_d_or_i(va_list args)
{
	int	num;

	num = va_arg(args, int);
	if (!num)
		return (print_null(zero));
	return (ft_putnbr_fd(num, 1));
}

int	handle_u(va_list args)
{
	unsigned int	num;

	num = (unsigned int)va_arg(args, unsigned int);
	if (!num)
		return (print_null(zero));
	return (ft_putunbr_fd(num, 1));
}

int	handle_p(va_list args)
{
	unsigned long	addr;
	int				count;

	count = 0;
	addr = (unsigned long)(va_arg(args, void *));
	if (!addr)
		return (print_null(nil));
	count += ft_putstr_fd("0x", 1);
	count += ft_put_hex(addr, 1, 'x');
	return (count);
}
