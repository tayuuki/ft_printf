CC := gcc
CFLAGS := -Wall -Wextra -Werror
INCDIRS = ./libft
NAME := libftprintf.a
OBJS = ft_printf.o \
		ft_itoaetc.o
ARFLAGS = cr

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(INCDIRS)
	cp $(INCDIRS)/libft.a ./$(NAME)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(MAKE) clean -C $(INCDIRS)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(INCDIRS)

re: fclean all

.PHONY:	all clean fclean re