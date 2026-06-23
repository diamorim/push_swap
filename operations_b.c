#include "push_swap.h"

void op_sb(t_stack *stack_b, t_prog_state *prog_state)
{
	t_node *top_node;
	t_node *new_top;

	if (!stack_b || stack_b->size < 2)
		return ;
	top_node = stack_b->top;
	new_top = top_node->next;
	if (new_top->next)
	{
		top_node->next = new_top->next;
		new_top->next = top_node;
		new_top->prev = top_node->prev;
		top_node->prev = new_top;
	}
	else
	{
		change_next_prev(top_node, new_top, new_top);
		change_next_prev(new_node, top_node, top_node);
	}
	stack_b->top = new_top;
	prog_state->ops_count_per_type[OP_SB]++;
	prog_state->ops_count_total++;
	ft_putstr_fd("sb\n", 1);
}
void op_pb(t_stack *stack_b, t_stack *stack_a, t_prog_state *prog_state)
{
	t_node *new_btop;
	t_node *top;

	if (!stack_a || !prog_state)
		return;
	if (!stack_a->top)
		return ;
	top = stack_a->top;
	if (top->next)
	{
		new_btop = top->next;
		new_btop->prev = top->prev;
		stack_add_front(stack_b, top);
		stack_a->top = new_btop;
	}
	else
	{
		stack_add_front(stack_b->top, stack_a->top);
		stack_a->top = NULL;
	}
	stack_a->size--;
	prog_state->ops_count_per_type[OP_PB]++;
	prog_state->ops_count_total++;
	ft_putstr_fd("pb\n", 1);
}
void ra_op(t_stack *stack_b, t_prog_state *state)
{
	if (!stack_b || !state)
		return ;
	stack_b->top = stack_b->top->next;
	state->ops_count_per_type[OP_RB]++;
	state->ops_count_total++;
	ft_putstr_fd("rb\n", 1);
}