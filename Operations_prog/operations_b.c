#include "../push_swap.h"

void op_sb(t_prog_state *state)
{
	t_node *top_node;
	t_node *new_top;
	t_stack *stack_b;

	if (!state->b || state->b->size < 2)
		return ;
	stack_b = state->b;
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
		change_next_prev(new_top, top_node, top_node);
	}
	stack_b->top = new_top;
	state->ops_count_per_type[OP_SB]++;
	state->ops_count_total++;
	ft_putstr_fd("sb\n", 1);
}
void op_pb(t_prog_state *state)
{
	t_node *new_btop;
	t_node *top;
	t_stack *stack_a;
	t_stack *stack_b;

	if (!state->a || !state)
		return;
	if (!state->a->top)
		return ;
	stack_a = state->a;
	stack_b = state->b;
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
		stack_add_front(stack_b, stack_a->top);
		stack_a->top = NULL;
	}
	stack_a->size--;
	state->ops_count_per_type[OP_PB]++;
	state->ops_count_total++;
	ft_putstr_fd("pb\n", 1);
}
void op_rb(t_prog_state *state)
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
void op_rrb(t_prog_state *state)
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
