#include "push_swap.h"

/*
	This is an optional function dispatcher
	to make the code a bit cleaner.

	I can change my other code if we don't want
	to use this.

*/

void	do_op(t_prog_state *state, t_op_type op)
{
	if (!state)
		return ;
	if (op == OP_SA)
		op_sa(state);
	else if (op == OP_SB)
		op_sb(state);
	else if (op == OP_SS)
		op_ss(state);
	else if (op == OP_PA)
		op_pa(state);
	else if (op == OP_PB)
		op_pb(state);
	else if (op == OP_RA)
		op_ra(state);
	else if (op == OP_RB)
		op_rb(state);
	else if (op == OP_RR)
		op_rr(state);
	else if (op == OP_RRA)
		op_rra(state);
	else if (op == OP_RRB)
		op_rrb(state);
	else if (op == OP_RRR)
		op_rrr(state);
	state->ops_count_total++;
}
