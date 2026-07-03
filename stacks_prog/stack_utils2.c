#include "../push_swap.h"

void	push_all_a(t_prog_state *state)
{
	int i;

	i = 0;
	while (i < state->b->size)
	{
		op_pa(state);
		i++;
	}
}