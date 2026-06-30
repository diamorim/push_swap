
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
	___ Important note ___
	'find_pos_min' is moved to stack_queries.c in stacks_prog folder.

*/

/*
	Handle stacks of size 0–3 so algorithm entry points stay DRY.
	Returns 1 if the caller should return immediately (small stack fully
	sorted), 0 if the caller should proceed with its main algorithm.
	Size 2: wastate only if the top element is greater than the second.
*/

int	handle_small_sort(t_prog_state *state)
{
	if (!state || !state->a)
		return (1);
	if (state->a->size <= 1)
		return (1);
	if (state->a->size == 2)
	{
		if (state->a->top->value > state->a->top->next->value)
			op_sa(state);
		return (1);
	}
	if (state->a->size == 3)
	{
		sort_3(state);
		return (1);
	}
	return (0);
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
