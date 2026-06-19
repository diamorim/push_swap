NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	main.c \
		check_flags.c \
	 	check_allflags.c \
		compute_disorder.c \
		ft_isnumber.c \
		ft_strtol.c \
		init_utils.c \
		input_parser.c \
		sort_strategy_dispatcher.c \
		sort_adaptive.c \
		sort_simple_selection.c \
		sort_medium_chunk.c \
		sort_complex.c \
		sort_utils.c \
		stack_utils.c



OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: all clean fclean re
