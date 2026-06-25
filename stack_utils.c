#include "push_swap.h"

/*
	__sort_utils.c__ has four functions:
		- new_node()
		- stack_add_back()
		- stack_add_front()
		- stack_last_node()

	___ Used by ___
		- parse_input() via input_parser.c

*/

/*
	__new_node()__
		This function simply allocates memory
		for a node and assigns to it
		whatever value is passed into it
		by the caller.

		There is nothing before or after
		this newly created node.
*/

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


/*
	__stack_add_back()__
		This function receives a pointer
		to a stack as well as a node
		and adds the node to the back of
		the stack.
*/

void	stack_add_back(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	if (!stack->top)
	{
		stack->top = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		last = stack->top->prev;
		last->next = new;
		new->prev = last;
		new->next = stack->top;
		stack->top->prev = new;
	}
	stack->size++;
}
void	stack_add_front(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	if (!stack->top)
	{
		stack->top = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		last = stack->top->prev;
		new->next = stack->top;
		new->prev = last;
		last->next = new;
		stack->top->prev = new;
		stack->top = new;
	}
	stack->size++;
}

t_node	*stack_last_node(t_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	return (stack->top->prev);
}
void change_next_prev(t_node *node, t_node *new_prev, t_node *new_next)
{
	if (!node || !new_next || !new_prev)
		return;
	node->next = new_next;
	node->prev = new_prev;
}
