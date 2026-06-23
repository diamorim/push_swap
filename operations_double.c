#include "push_swap.h"

void ss_op(t_stack *stack_a, t_stack *stack_b, t_prog_state *prog_state)
{
	if (!prog_state)
		return ;
	op_sa(stack_a, prog_state);
	op_sb(stack_b, prog_state);
	prog_state->ops_count_per_type[OP_SA]--;
	prog_state->ops_count_per_type[OP_SB]--;
	prog_state->ops_count_total--;
}
