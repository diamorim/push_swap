#include "../push_swap.h"
/*
	__sort_simple_selection.c__ includes:
		- sort_simple()

	___ Calls directly ____
		- 'sort3()' in sort_utils.c
		- 'handle_small_sort()' in sort_utils.c
		- 'smart_rotate()' in sort_utils.c
		- 'find_pos_min'
		- 'op_pb'
		- 'op_pa'


	__ Used by __
		- sort_strategy_dispatcher.c


	The purpose of these functions is to sort a stack
	with worst case efficiency of O(n^2) as chosen by
	the user or the adaptive algorithm based on the disorder
	metric (decided per adaptive algorithm).

	if there are 3 or less, then handle_small_sort takes
	care of the sorting and returns to the caller.

	othewise extract_lowest_to_b will push everything
	but the three elements with the smallest values to
	stack b and then sort stack a.

	then element by element, each element in stack b
	will be pushed back to stack a.

*/

#include "../push_swap.h"

void	sort_simple(t_prog_state *state)
{
 	if (handle_small_sort(state))
		return;
	extract_move_lowest_to_stack_b(state);
	sort_3(state);
	while (state->b->size > 0)
		op_pa(state);
}
