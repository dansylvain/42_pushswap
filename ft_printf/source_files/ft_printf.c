/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 06:43:39 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/11 15:00:57 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			char_printed;
	t_func_ptr	func_ptr[8];
	va_list		args;

	declare_func_ptr(func_ptr);
	char_printed = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			char_printed += (func_ptr[get_index(*(str + 1))](args));
			str++;
		}
		else
			char_printed += ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(args);
	return (char_printed);
}

void	declare_func_ptr(t_func_ptr *func_ptr)
{
	func_ptr[0] = handle_c;
	func_ptr[1] = handle_s;
	func_ptr[2] = handle_d_or_i;
	func_ptr[3] = handle_d_or_i;
	func_ptr[4] = handle_u;
	func_ptr[5] = handle_p;
	func_ptr[6] = handle_x_lowercase;
	func_ptr[7] = handle_x_uppercase;
	func_ptr[8] = handle_percent;
}

int	get_index(char c)
{
	char	*format_specifiers;
	int		i;

	format_specifiers = "csdiupxX%";
	i = 0;
	while (i < 9)
	{
		if (format_specifiers[i] == c)
			return (i);
		i++;
	}
	return (i);
}
