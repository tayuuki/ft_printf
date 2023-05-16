/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayuuki <tayuuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:33:48 by tayuuki           #+#    #+#             */
/*   Updated: 2023/05/16 20:33:49 by tayuuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	ft_putchr(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstr(char *str, int *count, bool flag)
{
	char	*tmp;

	tmp = str;
	if (!str)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		*count += 1;
		str++;
	}
	if (flag)
		free(tmp);
}

void	check_per(const char *format, int *count, va_list *ap)
{
	if (*format == 'c')
		ft_putchr(va_arg(*ap, int), count);
	else if (*format == 's')
		ft_putstr(va_arg(*ap, char *), count, false);
	else if (*format == 'd' || *format == 'i')
		ft_putstr(ft_itoa_ten(va_arg(*ap, int)), count, true);
	else if (*format == 'u')
		ft_putstr(ft_itoa_unsigned(va_arg(*ap, unsigned int)), count, true);
	else if (*format == 'x')
		ft_putstr(ft_itoa_x(va_arg(*ap, unsigned int), 0), count, true);
	else if (*format == 'X')
		ft_putstr(ft_itoa_x(va_arg(*ap, unsigned int), 32), count, true);
	else if (*format == 'p')
		ft_putstr(ft_pointer(va_arg(*ap, size_t)), count, true);
	else if (*format == '%')
		ft_putchr('%', count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check_per(format, &count, &ap);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(ap);
	return (count);
}
