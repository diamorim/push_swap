#include "../push_swap.h"

void	push_all_a(t_prog_state *state)
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