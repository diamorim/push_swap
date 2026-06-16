#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
// # include "ft_printf.h"
# include "libft/libft.h"

int	check_allflags(char **argv);
//same as atoi but works with long integers
int ft_strtol(char *str);
//a fucntion to check if a string is made only of numbers
int ft_isnumber(char *str);
//a function to check if the arguments are flags
int	check_flags(char *str);
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

typedef struct s_program_state
{
	t_stack		*a;
	t_stack		*b;
}	t_program_state;


#endif
