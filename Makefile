NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	main.c \
		stack_utils_00_init.c \
		stack_utils_01.c \
		stack_utils_03_queries.c \
		input_parser.c \
		input_utils_a.c \
		input_utils_b.c \
		input_utils_c.c \
		operations_a.c \
		operations_b.c \
		operations_double.c \
		operations_utils.c \
		print_op.c \
		sor_compute_disorder.c \
		sort_strategy_dispatcher.c \
		sort_adaptive.c \
		sort_simple.c \
		sort_medium_01_primary.c \
		sort_medium_02_compute_chunk.c \
		sort_medium_03_distribute_to_stack_b.c \
		sort_complex_01.c \
		sort_utils_01_handle_small_sort.c \
		sort_utils_02_extract_and_move_smart_rotate.c \
		sort_utils_03_rank.c

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
