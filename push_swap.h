#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>

# include "libft/libft.h"

int				check_maxint(char **argv);
int				check_allflags(char **argv);
long			ft_strtol(char *str);
int				ft_isnumber(char *str);
int				check_flags(char *str);
int				check_errors(int argc, char **argv);
int				reps_check(char **argv, int occ);

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;


typedef enum e_op_type
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_TYPES_TOTAL
}	t_op_type;



typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;


// bench is just boolean for the --bench benchmarking flag
// strat_req is the strategy requested by the user in CLI
// strat_used is the strategy our program uses
// if the user selects adaptive strategy (or it runs
// adaptive by default -- no user input)
// 'n' is the input size of number of elements
//

typedef struct s_prog_state
{
	t_stack		*a;
	t_stack		*b;
	int			n;
	int			ops_count_total;
	int			ops_count_per_type[OP_TYPES_TOTAL];
	t_strategy	strat_req;
	t_strategy	strat_used;
	int			bench;
	double		disorder;
}	t_prog_state;

// ___ initalization and freeing functions ___
t_stack			*init_stack(void);
t_prog_state	*init_prog_state(void);
void			free_stack(t_stack *stack);
void			free_prog_state(t_prog_state *state);


// _____ input_utils  _____
t_strategy		strategy_from_argv(char **argv);



// _____ stack_utils.c  _____
// used by sort_simple & sort_medium

t_node			*new_node(int value);
void			stack_add_front(t_stack *stack, t_node *new);
void			stack_add_back(t_stack *stack, t_node *new_node);
t_node			*stack_last_node(t_stack *stack);
void 			change_next_prev(t_node *node, t_node *new_prev, t_node *new_next);
int				*stack_to_arr(t_stack *stack);
void			push_all_a(t_prog_state *state);


// ___ parsing ___
int				parse_input(t_prog_state *state, char **argv);


// ___ operations engine ___
void	swap(t_stack *stack);
void	push(t_stack *stack_1, t_stack *stack_2);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	record_ops(t_prog_state *state, t_op_type op);

void	op_sa(t_prog_state *state);
void	op_pa(t_prog_state *state);
void	op_ra(t_prog_state *state);
void	op_rra(t_prog_state *state);
void	op_sb(t_prog_state *state);
void	op_pb(t_prog_state *state);
void	op_rb(t_prog_state *state);
void	op_rrb(t_prog_state *state);
void	op_ss(t_prog_state *state);
void	op_rr(t_prog_state *state);
void	op_rrr(t_prog_state *state);


//	___	algorithm-sorting - sorting_prog` ___
// Not including check_node here as functions with
// static return values should only be declared
// in the script that is calling them

double			compute_disorder(t_stack *s);
void			sort_adaptive(t_prog_state *state);
void			dispatch_algo_strategy(t_prog_state *state);
int				is_sorted_asc(t_stack *s);

void			sort_simple(t_prog_state *state);

void			sort_medium(t_prog_state *state);
void			sort_complex(t_prog_state *state);


//	___ sort_utils.c __
int				count_bits(int n);
void			sort_3(t_prog_state *state);
int				handle_small_sort(t_prog_state *state);
void			extract_min_to_three(t_prog_state *state);
void			smart_rotate(t_prog_state *state, t_stack *s, int pos);
void			quick_sort(int arr[], int low, int high);
int				partition(int arr[], int low, int high);
int				binary_search(int arr[], int n, int x);
void			rank(t_prog_state *state);
void			rank_stack(t_stack *s);
void			radix_sort(t_prog_state *state);
void			ft_swop(int *a, int *b);
void			distribute_to_b(t_prog_state *state, int chunk_size,
					int num_chunks, int n);

// ___ stack_queries.c
int				find_pos_min(t_stack *s);
int				find_pos_max(t_stack *s);

#endif
