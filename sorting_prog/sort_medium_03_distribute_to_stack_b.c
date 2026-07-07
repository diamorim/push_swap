#include "../push_swap.h"

static void	pull_elements_from_band(t_prog_state *state, int min,
				int max, int width);
static void	process_one_band(t_prog_state *state, int band, int chunk_size,
				int n);

//_____ distribute_to_stack_b _____
//	i is an index for each band
// chunk_size is the number of elements per band
// num_chunks -s the number of of chunks in the entire stack
//	n is the number of elements in the entire stack
//
// This function scans each chunk (aka band) one at a time and
// stores them into stack_b
//
void	distribute_to_stack_b(t_prog_state *state, int chunk_size,
			int num_chunks, int n)
{
	int	band_idx;

	band_idx = 0;
	while (band_idx < num_chunks)
	{
		process_one_band(state, band_idx, chunk_size, n);
		band_idx++;
	}
}

//_____ scan_one_band() _____
//
//
static void	process_one_band(t_prog_state *state, int band_idx, int chunk_size,
				int n)
{
	int	min;
	int	max;
	int	width;

	min = band_idx * chunk_size;
	max = min + chunk_size;
	if (max > n)
		max = n;
	width = max - min;
	pull_elements_from_band(state, min, max, width);
}


//_____ pull_elements_from_band() _____
// Each "band" is simply a chunk (a grouping of elements)
//
// Function examines each element in stack `a`:
// 		If the rank of the element fits within the current
// 		chunk's [min, max) range, push that element to stack 'b'.
//
// 			Then, if the rank of the element is in the lower half of
// 				the band, rotate it to the bottom of stack 'b' (op_rb)
// 				so that higher ranked elements (larger numbers) stay on top.
//
// 				This pre-sorts stack 'b' so that restore_to_stack_a()
// 					performs fewer operations.
//
//		Otherwise, rotate past it in stack 'a' via op_ra().
//
// 	Repeat this process until all relevant elements in the current chunk
//	have been moved to stack 'b'.
//

static void	pull_elements_from_band(t_prog_state *state, int min,
				int max, int width)
{
	int	pulled;
	int	rev;
	int	val;
	int	mid;

	pulled = 0;
	rev = 0;
	mid = (min + max) / 2;
	while (pulled < width && state->a->size > 0 && rev <= state->a->size)
	{
		val = state->a->top->rank;
		if (val >= min && val < max)
		{
			op_pb(state);
			if (val <= mid && state->b->size > 1)
				op_rb(state);
			pulled++;
			rev = 0;
		}
		else
		{
			op_ra(state);
			rev++;
		}
	}
}

//_____ push_elements_back_to_stack_a()_____
//	Function searches for the biggest element first and pushes
// this back to stack `a` in descdending order.
//
// It aims to do this as efficiently as possible via smart_rotate()
// by looking at whether its faster to rotate in one direction or
// the other.
//
void	push_elements_back_to_stack_a(t_prog_state *state)
{
	while (state->b->size > 0)
	{
		smart_rotate(state, state->b, find_pos_max(state->b));
		op_pa(state);
	}
}
