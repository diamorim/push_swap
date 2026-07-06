
#include "../push_swap.h"


static void	execute_rotation(t_prog_state *state, t_stack *s, int steps, int reverse_flag);

/*
	____ handle_small_sort() ____
		- 	This helper function acts as a disapatcher that
		sorts anything less than or equal to 3 elements in a
		stack (and returns a '1') or otherwise returns to
		caller so that it knows to perforn a sorting job
		on 4+ elements.
*/

int	handle_small_sort(t_prog_state *state)
{
	if (!state || !state->a)
		return (1);
	if (state->a->size <= 1)
		return (1);
	if (state->a->size == 2)
	{
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
	Sorts a 3-element stack in 1-or-2 operations.
	- Assumes state->a->size is exactly 3.
	- Guards against smaller sizes
	- 'a'= top, 'b' = middle, 'c'= bottom

	This is the most efficient algorithm when there
	are only 3 elements to be sorted (5 possible unsorted
	permutations).
*/

void	sort_3(t_prog_state *state)
{
	int	val_top;
	int	val_middle;
	int	val_bottom;

	if (!state || !state->a || state->a->size != 3)
		return ;
	val_top = state->a->top->value;
	val_middle = state->a->top->next->value;
	val_bottom = state->a->top->prev->value;
	if (val_top > val_middle && val_top > val_bottom)
	{
		if (val_middle > val_bottom)
		{
			op_sa(state);
			op_rra(state);
		}
		else
			op_ra(state);
	}
	else if (val_top > val_middle)
		op_sa(state);
	else if (val_middle > val_bottom)
	{
		if (val_top > val_bottom)
			op_rra(state);
		else
		{
			op_sa(state);
			op_ra(state);
		}
	}
}



//		____ extract_lowest_to_b ____
//		One by one, this function pushes
//		everything from stack a to stack b
//		except for the three largest values.
//
//		Note that the function uess 'smart_rotate'
// 		to figure out what is the most efficient direction
//		to get the element with the smallest value to the top.
//

void	extract_lowest_to_b(t_prog_state *state)
{
	int	min_pos;

	while (state->a->size > 3)
	{
		min_pos = find_pos_min(state->a);
		smart_rotate(state, state->a, min_pos);
		op_pb(state);
	}
}


/*
	__ smart_rotate() __
		- Attempts to rotate nodes in a given stack with
		the least number of ops possible.
		- Brings a node at a specific position to the top
		of a given stack.

		- Calculates if the position of an element is closer
		to the top or the bottom of the stack.

		pos 0  ← top
		pos 1
		pos 2
		pos 3
		pos 4   ← midpoint (size/2 = 5)
		pos 5
		pos 6
		pos 7
		pos 8
		pos 9  ← bottom

		- If the position of the element in the stack is in the:
			- first half ----->   rotates forward
			- second half ------> reverse rotates
*/



void	smart_rotate(t_prog_state *state, t_stack *s, int pos)
{
	int	reverse_flag;

	if (!state || !s)
		return ;
	if (pos == 0 || pos >= s->size)
		return ;
	if (pos <= s->size / 2)
	{
		reverse_flag = 0;
		execute_rotation(state, s, pos, reverse_flag);
	}
	else
	{
		reverse_flag = 1;
		execute_rotation(state, s, s->size - pos, reverse_flag);
	}
}

//
//
//


/*
 	__ execute_rotation() __
  - Executes 'rotate' on a given stack based on instructions
  from the caller -- smart_rotate()

  - Caller instructs:
  	- stack -- which stack to modify
    - direction - whether to rotate forwards or backwards
*/

static void	execute_rotation(t_prog_state *state, t_stack *s, int steps, int reverse_flag)
{
	int	i;

	i = 0;
	while (i < steps)
	{
		if (s == state->a)
		{
			if (reverse_flag)
				op_rra(state);
			else
				op_ra(state);
		}
		else
		{
			if (reverse_flag)
				op_rrb(state);
			else
				op_rb(state);
		}
		i++;
	}
}

///
///
///

void	ft_swop(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
