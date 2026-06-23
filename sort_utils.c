/*
	____ Purpose ____
		- Store shared utilities related
	to sorting elements inside of a
	stack.
 */
#include "push_swap.h"

int	find_sorted_prefix_len(t_stack *a)
{
	t_node	*curr;
	int		len;

	if (!a || a->size <= 1)
		return (a->size);
	curr = a->top;
	len = 1;
	while (len < a->size && curr->value <= curr->next->value)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}

int	find_insert_pos(t_stack *a, int value)
{
	t_node	*curr;
	t_node	*prev;
	int		i;

	if (a->size <= 1)
		return (0);
	curr = a->top;
	i = 0;
	while (i < a->size)
	{
		prev = curr->prev;
		if ((prev->value < curr->value
				&& value > prev->value && value < curr->value)
			|| (prev->value > curr->value
				&& (value < curr->value || value > prev->value)))
			return (i);
		curr = curr->next;
		i++;
	}
	return (0);
}
