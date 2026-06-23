#include "push_swap.h"

/*
	__sort_utils.c__ has two functions:
		- new_node()
		- stack_add_back()

	___ Used by ___
		- parse_input() via input_parser.c

	___ Note ___
		- If no other scripts are using these
		functions then let's consolidate into
		input_parser.c

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
		stack->top = new;
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
void	stack_add_front(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return ;
	if (!stack->top)
		stack->top = new;
	else
	{
		stack->top->prev = new;
		new->next = stack->top;
		stack->top = new;
	}
	new->prev = NULL;
	stack->size++;
}
t_node *stack_last_node(t_stack *stack)
{
	t_node *current_node;
	if (!stack || !stack->top)
		return NULL;
	current_node = stack->top;
	while (current_node->prev)
		current_node = current_node->prev;
	return current_node;
}