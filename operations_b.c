#include "push_swap.h"

void sb_op(t_prog_state *prog_state)
{
	t_node *top_node;
	t_node *new_top;
	t_stack *stack_b;

	if (!prog_state->b || stack_b->size < 2)
		return ;
	stack_b = prog_state->b;
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
void pa_op(t_prog_state *prog_state)
{
	t_node *new_btop;
	t_node *top;
	t_stack *stack_a;
	t_stack *stack_b;

	if (!prog_state->a || !prog_state)
		return;
	if (!prog_state->a->top)
		return ;
	stack_a = prog_state->a;
	stack_b = prog_state->b;
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
void rb_op(t_prog_state *state)
{
	t_stack *stack_b;
	if (!state->b || !state)
		return ;
	stack_b = state->b;
	stack_b->top = stack_b->top->next;
	state->ops_count_per_type[OP_RB]++;
	state->ops_count_total++;
	ft_putstr_fd("rb\n", 1);
}
rrb_op(t_prog_state *state)
{
		t_stack *stack_b;
	if (!state->b || !state)
		return ;
	stack_b = state->b;
	stack_b->top = stack_b->top->prev;
	state->ops_count_per_type[OP_RRB]++;
	state->ops_count_total++;
	ft_putstr_fd("rrb\n", 1);
}