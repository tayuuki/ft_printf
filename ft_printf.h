/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayuuki <tayuuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:36:42 by tayuuki           #+#    #+#             */
/*   Updated: 2023/05/16 20:36:43 by tayuuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libc.h>
# include <stdarg.h>
# include <stdbool.h>

char	*ft_strrev(char *tmp, int size, int flag);
char	*ft_itoa_ten(int n);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_itoa_x(unsigned int n, int upper);
char	*ft_pointer(size_t n);
int		ft_abs(int num);
void	ft_putchr(char c, int *count);
void	ft_putstr(char *str, int *count, bool flag);
void	check_per(const char *format, int *count, va_list *ap);
int		ft_printf(const char *format, ...);

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif