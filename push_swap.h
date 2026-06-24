#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
// # include "ft_printf.h"
# include "libft/libft.h"

int	check_allflags(char **argv);
//same as atoi but works with long integers
long ft_strtol(char *str);
//a function to check if a string is made only of numbers
int ft_isnumber(char *str);
//a function to check if the arguments are flags
int				check_flags(char *str);
int				check_errors(int argc, char **argv);
int				check_maxint(char **argv);
int				reps_check(char **argv, int occ);


//	___	algorothm-sorting ___
double			compute_disorder(t_stack *s);
// Not including check_node here as functions with
// static return values should only be declared
// in the script that is calling them
//

void			dispatch_algo_strategy(t_prog_state *state);
int				is_sorted_asc(t_stack *s);

void			sort_adaptive(t_prog_state *state);
void			sort_simple(t_prog_state *state);
void			sort_medium(t_prog_state *state);
void			sort_complex(t_prog_state *state);



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

// ____ Regarding `11` vs OP_TYPES_TOTAL as enum ____
//	- I replaced the enum with 11. From my research
// we cannot use const int for this -- relates to
// compile time requirements in C. We can otherwise
// use enum (this is normal way), #define, or
// hardcoding. In this case, it's not a big deal
// to hardcode since we only use it here.
//
typedef struct s_prog_state
{
	t_stack		*a;
	t_stack		*b;
	int			n;
	int			ops_count_total;
	int			ops_count_per_type[11];
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

// _____ stack utilities _____
// used by sort_simple & sort_medium
//
t_node			*stack_last_node(t_stack *stack);
t_node			*new_node(int value);
void			stack_add_back(t_stack *stack, t_node *new_node);
void 			change_next_prev(t_node *node, t_node *new_prev, t_node *new_next);
// ____ adds a new node at the top of the stack, it deals with the next and previous node.
void			stack_add_front(t_stack *stack, t_node *new);

// ___ parsing ___
int				parse_input(t_prog_state *state, char **argv);


// ___ operations engine ___

void op_sa(t_prog_state *state);
void op_pa(t_prog_state *state);
void op_ra(t_prog_state *state);
void op_rra(t_prog_state *state);
void op_sb(t_prog_state *state);
void op_pb(t_prog_state *state);
void op_rb(t_prog_state *state);
void op_rrb(t_prog_state *state);
void op_ss(t_prog_state *state);
void op_rr(t_prog_state *state);
void op_rrr(t_prog_state *state);


#endif
