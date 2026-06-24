#include "push_swap.h"

void op_ss(t_prog_state *state)
{
	if (!state)
		return ;
	op_sa(state);
	op_sb(state);
	state->ops_count_per_type[OP_SA]--;
	state->ops_count_per_type[OP_SB]--;
	state->ops_count_per_type[OP_SS]++;
	state->ops_count_total--;
}
void op_rr(t_prog_state *state);
void op_rrr(t_prog_state *state);
