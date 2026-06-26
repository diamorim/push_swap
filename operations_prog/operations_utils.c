#include "../push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*new_top;
	t_node	*old_top;

	if (!stack || stack)
		return ;
	old_top = stack->top;
	new_top = old_top->next;

	if (old_top->prev)
	{
		old_top->prev->next = new_top;
	}
	
}