#include "../push_swap.h"

void op_sb(t_prog_state *state) {
	if (!state || !state->b || state->b->size < 2)
		return;
	swap(state->b);
	record_ops(state, OP_SB);
	ft_putstr_fd("sb\n", 1);
}

void op_pb(t_prog_state *state) {
	if (!state || !state->b)
		return;
	push(state->a, state->b);
	record_ops(state, OP_PB);
	ft_putstr_fd("pb\n", 1);
}

void op_rb(t_prog_state *state) {
	if (!state || !state->b)
		return;
	rotate(state->b);
	record_ops(state, OP_RB);
	ft_putstr_fd("rb\n", 1);
}

void op_rrb(t_prog_state *state)
{
	if (!state || !state->b)
		return;
	reverse_rotate(state->b);
	record_ops(state, OP_RRB);
	ft_putstr_fd("rrb\n", 1);
}
