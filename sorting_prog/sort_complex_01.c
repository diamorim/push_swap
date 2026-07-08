#include "../push_swap.h"

void	rank(t_prog_state *state);
int		count_bits(int n);
void	push_all_to_stack_a(t_prog_state *state);


///
// ---- sort_complex ____
// Function calculates and assigns a rank to all of
// the values inside of a given stack.
//
//
//
void	sort_complex(t_prog_state *state)
{
	int	stack_size;
	int	bit;
	int	biggest_bit;
	int	i;

	rank(state);
	stack_size = state->a->size;
	bit = 0;
	i = 0;
	biggest_bit = count_bits(stack_size - 1);
	while (bit < biggest_bit)
	{
		while (i < stack_size)
		{
			if ((state->a->top->rank >> bit) & 1)
				op_ra(state);
			else
				op_pb(state);
			i++;
		}
		i = 0;
		push_all_to_stack_a(state);
		bit++;
	}
}

//
// ____ count_bits ____
// Function counts how many bits are neede to
// represent a given number, `n`.
//
// I (Noah) don't get this yet....
//

int	count_bits(int n)
{
	int bits;

	bits = 0;
	while (n > 0)
	{
		n = n >> 1;
		bits++;
	}
	return (bits);
}

//
// ____ push_all_to_stack_a ____
// Function pushes nodes from stack b to
// stack a from top to bottom (??)
//
// I, Noah, need to visualize this some more times.
//

void	push_all_to_stack_a(t_prog_state *state)
{
	int i;
	int	target;

	target = state->b->size;
	i = 0;
	while (i < target)
	{
		op_pa(state);
		i++;
	}
}
