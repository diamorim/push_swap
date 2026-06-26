#include "push_swap.h"

void	op_sa(t_prog_state *state)
{
	if (!state || !state->a)
		return ;
	swap(state->a);
	record_op(state, OP_SA, "sa\n");
}

void	op_sb(t_prog_state *state)
{
	if (!state || !state->b)
		return ;
	swap(state->b);
	record_op(state, OP_SB, "sb\n");
}

void	op_ss(t_prog_state *state)
{
	if (!state || !state->a || !state->b)
		return ;
	swap(state->a);
	swap(state->b);
	record_op(state, OP_SS, "ss\n");
}
