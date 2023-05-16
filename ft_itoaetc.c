/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaetc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayuuki <tayuuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:34:08 by tayuuki           #+#    #+#             */
/*   Updated: 2023/05/16 20:34:09 by tayuuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str, int size, int flag)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, str, size + 1);
	if (flag == 1)
		tmp[i++] = '-';
	else if (flag == 2)
	{
		tmp[i++] = '0';
		tmp[i++] = 'x';
	}
	while (i < size)
	{
		tmp[i] = str[size - i - 1];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_itoa_ten(int n)
{
	char	str[12];
	int		i;
	int		minus;

	ft_bzero(str, 12);
	minus = 0;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		minus = 1;
	i = 0;
	while (n != 0)
	{
		str[i] = ft_abs(n % 10) + '0';
		n /= 10;
		i++;
	}
	return (ft_strrev(str, ft_strlen(str) + minus, minus));
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	str[12];
	int		i;

	ft_bzero(str, 12);
	i = 0;
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	return (ft_strrev(str, ft_strlen(str), 0));
}

char	*ft_itoa_x(unsigned int n, int upper)
{
	char	str[12];
	int		i;

	ft_bzero(str, 12);
	i = 0;
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		if (n % 16 < 10)
			str[i] = n % 16 + '0';
		else
			str[i] = n % 16 + 'a' - 10 - upper;
		n /= 16;
		i++;
	}
	return (ft_strrev(str, ft_strlen(str), 0));
}

char	*ft_pointer(size_t n)
{
	char	str[10];
	int		i;

	ft_bzero(str, 10);
	i = 0;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		if (n % 16 < 10)
			str[i] = n % 16 + '0';
		else
			str[i] = n % 16 + 'a' - 10;
		n /= 16;
		i++;
	}
	return (ft_strrev(str, ft_strlen(str) + 2, 2));
}
