CC = gcc
CFLAGS = -Wall -Wextra #-Werror
LIBFLAGS = -L libft/ -lft

NAME = push_swap

SRCS = src/push_swap.c src/swap.c src/push.c src/rotate.c src/check.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFLAGS)

clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJS)
	
fclean:
	$(MAKE) fclean -C libft
	rm -rf $(OBJS) $(NAME)

re: clean all