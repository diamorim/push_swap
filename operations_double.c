#include "push_swap.h"

void ss_op(t_prog_state *prog_state)
{
	if (!prog_state)
		return ;
	op_sa(prog_state);
	op_sb(prog_state);
	prog_state->ops_count_per_type[OP_SA]--;
	prog_state->ops_count_per_type[OP_SB]--;
	prog_state->ops_count_per_type[OP_SS]++;
	prog_state->ops_count_total--;
}
void rr()