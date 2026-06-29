#include "../push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*new_top;
	t_node	*old_top;

	if (!stack || stack->size < 2)
		return ;
	old_top = stack->top;
	new_top = old_top->next;
	if (stack->size > 2)
	{
		old_top->prev->next = new_top;
		new_top->next->prev = old_top;
	}
	old_top->next = new_top->next;
	new_top->prev = old_top->prev;
	old_top->prev = new_top;
	new_top->next = old_top;
	stack->top = new_top;
}

void	push(t_stack *stack_1, t_stack *stack_2)
{
	t_node	*top_1;

	if (!stack_1)
		return ;
	top_1 = stack_1->top;
	if (stack_1->size > 1)
	{
		top_1->prev->next = top_1->next;
		top_1->next->prev = top_1->prev;
		stack_1->top = top_1->next;
	}
	else
		stack_1->top = NULL;
	stack_add_front(stack_2, top_1);
	stack_1->size--;
}

void	rotate(t_stack *stack)
{
	if(!stack || stack->size < 2)
		return ;
	stack->top = stack->top->next;
}

void	reverse_rotate(t_stack *stack)
{
	if(!stack || stack->size < 2)
		return ;
	stack->top = stack->top->prev;
}
void	record_ops(t_prog_state *state, t_op_type op)
{
	state->ops_count_per_type[op]++;
	state->ops_count_total++;
}
