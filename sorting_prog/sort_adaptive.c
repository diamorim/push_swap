#include "../push_swap.h"

void	sort_adaptive(t_prog_state *state)
{
	double	disorder;

	if (!state || !state->a)
		return ;
	disorder = state->disorder;
	if (disorder < 0.2)
		sort_simple(state);
	else if (disorder >= 0.2 && disorder < 0.5)
	 	sort_medium(state);
	else
		sort_complex(state);
}
