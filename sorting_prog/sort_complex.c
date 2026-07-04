#include "../push_swap.h"

void	radix_sort(t_prog_state *state);

void sort_complex(t_prog_state *state)
{
	radix_sort(state);
}

//

void	radix_sort(t_prog_state *state)
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
		push_all_a(state);
		bit++;
	}
}
