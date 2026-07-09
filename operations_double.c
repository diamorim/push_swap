#include "../push_swap.h"

void op_ss(t_prog_state *state)
{
	if (!state || !state->a || !state->b
		|| state->a->size < 2 || state->b->size < 2)
		return ;
	op_sa(state);
	op_sb(state);
	state->ops_count_per_type[OP_SA]--;
	state->ops_count_per_type[OP_SB]--;
	state->ops_count_per_type[OP_SS]++;
	state->ops_count_total--;
}

void op_rr(t_prog_state *state)
{
	if (!state || !state->a || !state->b
		|| state->a->size < 2 || state->b->size < 2)
		return ;
	op_ra(state);
	op_rb(state);
	state->ops_count_per_type[OP_RA]--;
	state->ops_count_per_type[OP_RB]--;
	state->ops_count_per_type[OP_RR]++;
	state->ops_count_total--;
}

void op_rrr(t_prog_state *state)
{
	if (!state || !state->a || !state->b
		|| state->a->size < 2 || state->b->size < 2)
	return ;
	op_rra(state);
	op_rrb(state);
	state->ops_count_per_type[OP_RRA]--;
	state->ops_count_per_type[OP_RRB]--;
	state->ops_count_per_type[OP_RRR]++;
	state->ops_count_total--;
}
