/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:46:31 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/11 15:01:04 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	long int	num;
	int			i;

	i = get_nbr_str_len(n);
	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	ft_putchar_fd((num % 10) + '0', fd);
	return (i);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	long unsigned int	num;
	int					i;

	i = get_nbr_str_len(n);
	num = n;
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	ft_putchar_fd((num % 10) + '0', fd);
	return (i);
}

int	ft_put_hex(unsigned long n, int fd, char case_type)
{
	char	*base;
	int		count;

	count = 0;
	if (case_type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_put_hex(n / 16, fd, case_type);
	ft_putchar_fd(base[n % 16], fd);
	count++;
	return (count);
}
