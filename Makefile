CC := gcc
CFLAGS := -Wall -Wextra -Werror
INCDIRS = ./libft
NAME := libftprintf.a
OBJS = ft_printf.o \
		ft_itoaetc.o
ARFLAGS = cr

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	$(MAKE) -C $(INCDIRS)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(INCDIRS)


fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(INCDIRS)

re: fclean all
	$(MAKE) re -C $(INCDIRS)

.PHONY:	all clean fclean re