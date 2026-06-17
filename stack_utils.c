#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_add_back(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	if (!stack->top)
	{
		stack->top = new;
	}
	else
	{
		last = stack->top;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
	stack->size++;
}
