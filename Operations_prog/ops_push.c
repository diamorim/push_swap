#include "push_swap.h"

void	op_pa(t_prog_state *state)
{
	if (!state || !state->a || !state->b)
		return ;
	//push(state->a, state->b);
	//record_op(state, OP_PA, "pa\n");
}

void	op_pb(t_prog_state *state)
{
	if (!state || !state->a || !state->b)
		return ;
	//push(state->b, state->a);
	//record_op(state, OP_PB, "pb\n");
}
