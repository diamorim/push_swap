#include "../push_swap.h"

static void	pull_elements_from_band(t_prog_state *state, int min,
				int max, int width);
static void	process_one_band(t_prog_state *state, int band, int chunk_size,
				int n);

//_____ distribute_to_stack_b _____
//	band_idx 	= an index for each band
//	chunk_size	= the number of elements per band
//	num_chunks	= the number of of chunks in the entire stack
//	n 			= the number of elements in stack 'a'
//
// Each chunk is a band. Each band is a chunk.
//
//	Before this function has been called, the program calculates
//	how much to divide the total number of elements of stack into smaller
//	chunks using compute_chunk
// 					(e.g.
// 					000 - 100 (band 0)
// 					101	- 200 (band 1)
// 					201	- 300 (band 2)
// 					301	- 400 (band 3)
// 					etc.)
//
//	This function scans the entire stack to identify each element that fits
//	within a specific range of a given band and then moves those elements
//	from stack 'a' to stack 'b'.
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
//	min		=	the lowest range of a given band being processed
//	max		=	the highest range of a given band being processed
//	width 	= 	the number of elements to process in a given band
//
//	Going back to this example of bands:
// 					(e.g.
// 					000 - 100 (band 0)
// 					101	- 200 (band 1)
// 					201	- 300 (band 2)
// 					301	- 400 (band 3)
// 					etc.)
//
// In the first band:
// 		 			min		= 0
// 					max		= 100
// 					width	= 101
//
// In the second band
// 					min		= 101
// 					max 	= 200
// 					width	= 100
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
// moved	=	# of elements pulled from stack 'a' to stack 'b'
// 				in a given round (using this function)
// rev		=	# of rotations ("revolutions") since last time an element
// 				was pushed from stack 'a' to stack 'b'
// r		= 	the rank of a given element being examined in stack 'a'
//
// The idea of the function is to push elements from stack 'a' to stack 'b'
// such that elements with a higher rank (they hold larger values relative to
// elements with a lower rank) are at the top of stack 'b'.
// e.g. 8 		7		7
// 		7		8		8
// 		3		3		2
// 		2		2		3
//
// The function does not perfectly sort the elements.
//
// Rather, it's more like a pre-sort -- which decreases future operations.
//
// Function examines each element in stack `a`:
// 		If the rank of the element fits within the current
// 		chunk's [min, max) range, push that element to stack 'b'.
//
//		Otherwise, rotate to next element in stack 'a' via op_ra().
//
// 		Repeat this process until all relevant elements in the current chunk
//		have been moved to stack 'b'.
//
//		The more bands that have been sorted, the fewer elements in stack 'a' to process
// 		so the sorting process moves more quickly over time.
//

static void	move_elements_to_stack_b(t_prog_state *state, int min,
				int max, int width)
{
	int	moved;
	int	rev;
	int	r;
//	int	mid;

	moved = 0;
	rev = 0;
//	mid = (min + max) / 2;
	while (moved < width && state->a->size > 0 && rev <= state->a->size)
	{
		r = state->a->top->rank;
		if (r >= min && r < max)
		{
			op_pb(state);
//			if (r <= mid && state->b->size > 1)
//				op_rb(state);
			moved++;
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
//	Function searches for the position of the element with the highest value
// and rotates the stack so that this element is at the top of stack 'b' and
// then pushes that element over to stack 'a'
//
// We use smart_rotate() to minimize the number of rotations required
// by first looking at whether its faster to rotate in one direction or
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
