
/*
	__sort_simple_selection.c__ includes:
		- sort_simple()
		- handle_small_sort()
		- sort_3()

	__ Uses __
		- stack_queries.c
		- operations_do_op()

	___ Uses indirectly functions in ___
		- operations_a.c
		- operations_b.c
		- operations_double.c

	__ Used by __
		- sort_strategy_dispatcher.c


	The purpose of these functions is to sort a stack
	with worst case efficiency of O(n^2) as chosen by
	the user or the adaptive algorithm based on the disorder
	metric (decided per adaptive algorithm).
*/

#include "../push_swap.h"

// void	sort_simple(t_prog_state *state)
// {
// 	if (handle_small_sort(state))
// 		return ;
// 	while (state->a->size > 3)
// 	{
// 		smart_rotate(state, state->a, find_pos_min(state->a));
// 		do_op(state, OP_PB);
// 	}
// 	sort_3(state);
// 	while (state->b->size > 0)
// 		do_op(state, OP_PA);
// }


/*
	Handle stacks of size 0–3 so algorithm entry points stay DRY.
	Returns 1 if the caller should return immediately (small stack fully
	sorted), 0 if the caller should proceed with its main algorithm.
	Size 2: swastate only if the top element is greater than the second.
*/
// int	handle_small_sort(t_prog_state *state)
// {
// 	if (state->a->size <= 1)
// 		return (1);
// 	if (state->a->size == 2)
// 	{
// 		if (state->a->top->value > state->a->top->next->value)
// 			do_op(state, OP_SA);
// 		return (1);
// 	}
// 	if (state->a->size == 3)
// 	{
// 		sort_3(state);
// 		return (1);
// 	}
// 	return (0);
// }



/*
	Sort exactly 3 elements in stack A in at most 2 operations.
	Precondition: state > a->size == 3 (caller must guard smaller sizes).
	Reads values as a=top, b=middle, c=bottom.
	Hardcodes all 5 unsorted permutations with known-optimal sequences.
*/
// void	sort_3(t_prog_state *state)
// {
// 	int	a;
// 	int	b;
// 	int	c;

// 	a = state->a->top->value;
// 	b = state->a->top->next->value;
// 	c = state->a->top->prev->value;
// 	if (a > b && a > c)
// 	{
// 		if (b > c)
// 		{
// 			do_op(state, OP_SA);
// 			do_op(state, OP_RRA);
// 		}
// 		else
// 			do_op(state, OP_RA);
// 	}
// 	else if (a > b)
// 		do_op(state, OP_SA);
// 	else if (b > c)
// 	{
// 		if (a > c)
// 			do_op(state, OP_RRA);
// 		else
// 		{
// 			do_op(state, OP_SA);
// 			do_op(state, OP_RA);
// 		}
// 	}
// }
