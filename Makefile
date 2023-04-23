CC := gcc
CFLAGS := -Wall -Wextra -Werror
INCDIRS = ./libft
NAME := libftprintf.a
OBJS = ft_printf.o / ft_itoaetc.C

all: $(NAME)

$(NAME): $(OBJS)
	ar cr $@ $^
	$(MAKE) -C libft

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C libft


fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all
	$(MAKE) re -C libft

.PHONY:	all clean fclean re