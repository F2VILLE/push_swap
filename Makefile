CC := cc
CF := -Wall -Werror -Wextra
NAME := push_swap
SRCS := ./push_swap.c ./stack_op.c ./stack.c ./stack_macro.c
OBJS := ${SRCS:.c=.o}

all: $(NAME) | libft/libft.a

debug:
	$(MAKE) CF="-D DEBUG_MODE=1" all

libft/libft.a: 
	make -C libft bonus

$(NAME): $(OBJS) | libft/libft.a
	$(CC) $(CF) -o $(NAME) $^ libft/libft.a

%.o: %.c
	$(CC) $(CF) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
