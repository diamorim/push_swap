
#include "../push_swap.h"
/*
	__sort_utils.c__ has functions:
		- find_pos_min()
		- smart_rotate()

	These helper funcitons are used by:
		- sort_simple_simple()
		- sort_simple_adaptive() - indirectly


		May be called in the future by:
		- sort_medium_chunk()
*/

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

/*
 	__ smart_rotate() __
 		Attempts to rotate nodes in a given stack with
 		the least number of operations possible using
 		the allowed operations in _op() function.

 		First, smart_rotate() identifies whether pos is in
 		the first half of the stack or the second half of the stack.

 		If it's in the first half, smart_rotate() rotates
 		the nodes forward..

 		If the 'pos' is in the second half, smart_rotate*( ) will
 		reverse rotate the nodes backwards.
*/

 	void	smart_rotate(t_prog_state *state, t_stack *s, int pos)
 	{
 		int			steps;
		int			i;

		if (!state || !s)
 			return ;
 		if (pos == 0 || pos >= s->size)
 			return ;
 	 	i = 0;
 		if (pos <= s->size / 2)
 		{
 			steps = pos;
			while (i < steps )
			{
				if (s == state->a)
					op_ra(state);
				else
					op_rb(state);
				i++;
			}
		}
 		else
 		{
 	 		steps = s->size - pos;
	 		while (i <steps)
			{
				if (s == state->a)
					op_rra(state);
				else
					op_rrb(state);
				i++;
			}
		}
	}
