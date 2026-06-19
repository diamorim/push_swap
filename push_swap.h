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


// ___ parsing ___
int				parse_input(t_prog_state *state, char **argv);



// ___ initalization and freeing functions ___
t_stack			*init_stack(void);
t_prog_state	*init_prog_state(void);
void			free_stack(t_stack *stack);
void			free_prog_state(t_prog_state *state);



// ___ stack utilities ___ (not sure need these actually...)
//t_node			*new_node(int value);
//void			stack_add_back(t_stack *stack, t_node *new_node);


//	___	algorothm-sorting ___
double			compute_disorder(t_stack *a)

void			dispatch_algo_strategy(t_prog_state *prst)
int				is_sorted_asc(t_stack *s)

void			sort_adaptive(t_prog_state *psrst);
void			sort_simple(t_prog_state *prst);
void			sort_medium(t_prog_state *prst);
void			sort_medium(t_prog_state *prst);
void			sort_complex(t_prog_state *prst);



typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

/*
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
*/


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

#endif
