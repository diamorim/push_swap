/*
	Will insert various queries here in order to
	analyze  the order of elements within a given
	stack.

	___ Used by ___
		This will be used by sorting algorithms -- at least
		sort_simple and sort and sort_medium.

	___ Note ___
		Maybe its better to place these in
		'stack_utils.c' rather than keep
		them here.


 */

#include "../push_swap.h"


/*
 	__ find_pos_min() __
  		Finds, and returns, the position
		in a given stack for the *smallest*
		value stored starting at the 'top'.

		The `top` of the stack is position `0`
		and the `bottom` of the stack is `size`.
*/

 int	find_pos_min(t_stack *s)
 {
 	t_node	*curr;
 	int		i;
 	int		pos_min;
 	int		val_min;

 	if (!s || s->size <= 1)
 		return (0);
 	curr = s->top;
 	pos_min = 0;
 	val_min = curr->value;
 	i = 0;
 	while (i < s->size)
 	{
 		if (curr->value < val_min)
 		{
 			val_min = curr->value;
 			pos_min = i;
 		}
 		curr = curr->next;
 		i++;
 	}
 	return (pos_min);
}

int	find_pos_max(t_stack *s)
{
	t_node	*curr;
	int		pos_max;
	int		val_max;
	int		i;

	if (!s || s->size <= 1)
		return (0);
	curr = s->top;
	pos_max = 0;
	val_max = curr->value;
	i = 0;
	while (i < s->size)
	{
		if (curr->value > val_max)
		{
			val_max = curr->value;
			pos_max = i;
		}
		curr = curr->next;
		i++;
	}
	return (pos_max);
}
