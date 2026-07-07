NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	main.c \
		stacks_prog/init_utils.c \
		stacks_prog/stack_queries.c \
		stacks_prog/stack_utils.c \
		input_prog/input_parser.c \
		input_prog/input_utils_a.c \
		input_prog/input_utils_b.c \
		operations_prog/operations_a.c \
		operations_prog/operations_b.c \
		operations_prog/operations_double.c \
		operations_prog/operations_utils.c \
		sorting_prog/sor_compute_disorder.c \
		sorting_prog/sort_strategy_dispatcher.c \
		sorting_prog/sort_adaptive.c \
		sorting_prog/sort_simple.c \
		sorting_prog/sort_medium_01.c \
		sorting_prog/sort_medium_02.c \
		sorting_prog/sort_medium_03.c \
		sorting_prog/sort_complex_01.c \
		sorting_prog/sort_complex_02.c \
		sorting_prog/sort_utils_01.c \
		sorting_prog/sort_utils_02.c \

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
