/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:51:10 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/15 18:14:25 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef enum t_null_output
{
	zero,
	nil,
	null
}	t_null_output;

typedef int	(*t_func_ptr)(va_list);

int		get_nbr_str_len(long int n);
void	declare_func_ptr(t_func_ptr *func_ptr);
int		ft_printf(const char *str, ...);
int		get_index(char c);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_put_hex(unsigned long n, int fd, char case_type);
int		handle_c(va_list args);
int		handle_s(va_list args);
int		handle_d_or_i(va_list args);
int		handle_u(va_list args);
int		handle_p(va_list args);
int		handle_x_lowercase(va_list args);
int		handle_x_uppercase(va_list args);
int		handle_percent(va_list args);
int		print_null(t_null_output null_value);

#endif