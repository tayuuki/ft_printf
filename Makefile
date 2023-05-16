CC := gcc
CFLAGS := -Wall -Wextra -Werror
NAME := libftprintf.a
OBJS = ft_printf.o \
		ft_itoaetc.o \
		ft_libft.o
ARFLAGS = cr

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re