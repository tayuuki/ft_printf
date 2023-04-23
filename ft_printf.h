#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include"libft/libft.h"
#include<libc.h>
#include<stdarg.h>


char	*ft_strrev(char *tmp, int size, int flag);
char	*ft_itoa_ten(int n);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_itoa_xX(unsigned int n, int upper);
char	*ft_pointer(size_t n);
int		ft_abs(int num);
void	ft_putchr(char c, int *count);
void	ft_putstr(char *str, int *count);
void	check_per(const char *format, int *count, va_list ap);
int		ft_printf(const char *format, ...);


#endif