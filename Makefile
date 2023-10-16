CC = gcc
CFLAGS = #-Wall -Wextra -Werror
NAME = push_swap
libft = libft/libft.a
SRCS = src/push_swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft/
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

srcs/%.o: srcs/%.c
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C libft/
	rm -rf $(OBJS)

fclean:
	$(MAKE) fclean -C libft/
	rm -rf $(OBJS) $(NAME)

re: clean all