#include "ft_printf.h"

int ft_abs(int num)
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

void	ft_putstr(char *str, int *count)
{
	while (*str)
	{
		write(1, str, 1);
		*count += 1;
		str++;
	}
}

void check_per(const char *format, int *count, va_list ap)
{
	if (*format == 'c')
		ft_putchr(va_arg(ap, int), count);
	else if (*format == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (*format == 'd' || *format == 'i')
		ft_putstr(ft_itoa(va_arg(ap, int)), count);
	else if (*format == 'u')
		ft_putstr(ft_itoa_unsigned(va_arg(ap, unsigned int)), count);
	else if (*format == 'x')
		ft_putstr(ft_itoa_xX(va_arg(ap, unsigned int), 0), count);
	else if (*format == 'X')
		ft_putstr(ft_itoa_xX(va_arg(ap, unsigned int), 32), count);
	else if (*format == 'p')
		ft_putstr(ft_pointer(va_arg(ap, size_t)), count);
	else if (*format == '%')
		ft_putchr('%', count);
	else if (*format == '%')
		ft_putchr('%', count);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check_per(format, &count, ap);
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