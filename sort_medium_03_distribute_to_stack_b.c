/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_03_distribute_to_stack_b.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 15:43:35 by diamo             #+#    #+#             */
/*   Updated: 2026/07/10 14:16:20 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_one_chunk(t_prog_state *state, int chunk, int chunk_size,
				int n);
static void	move_elements_to_stack_b(t_prog_state *state, int min,
				int max, int width);

//_____ distribute_to_stack_b _____
//	chunk_idx 	= an index for each chunk
//	chunk_size	= the number of elements per chunk
//	num_chunks	= the number of chunks in the entire stack
//	n 			= the number of elements in stack 'a'
//
//	Before this function has been called, the program calculates
//	how much to divide the total number of elements of stack into smaller
//	chunks using compute_chunk_size()
// 					(e.g.
// 					000 -  99 (chunk 0)
// 					100	- 199 (chunk 1)
// 					200	- 299 (chunk 2)
// 					300	- 399 (chunk 3)
// 					etc.)
//
//	This function scans the entire stack to identify each element that fits
//	within a specific range of a given chunk and then moves those elements
//	from stack 'a' to stack 'b'.
//
void	distribute_to_stack_b(t_prog_state *state, int chunk_size,
			int num_chunks, int n)
{
	int	chunk_idx;

	chunk_idx = 0;
	while (chunk_idx < num_chunks)
	{
		process_one_chunk(state, chunk_idx, chunk_size, n);
		chunk_idx++;
	}
}

//_____ process_one_chunk() _____
//	min		=	the lowest range of a given chunk being processed
//	max		=	the highest range of a given chunk being processed
//	width 	= 	the number of elements to process in a given chunk
//
//	Going back to this example of chunks:
// 					(e.g.
// 					0   -  99 (chunk 0)
// 					100 - 199 (chunk 1)
// 					200 - 299 (chunk 2)
// 					300 - 399 (chunk 3)
// 					etc.)
//
// In the first chunk:
// 		 			min		= 0
// 					max		= 100
// 					width	= 100
//
// In the second chunk
// 					min		= 100
// 					max 	= 200
// 					width	= 100
//
//
static void	process_one_chunk(t_prog_state *state, int chunk_idx,
			int chunk_size, int n)
{
	int	min;
	int	max;
	int	width;

	min = chunk_idx * chunk_size;
	max = min + chunk_size;
	if (max > n)
		max = n;
	width = max - min;
	move_elements_to_stack_b(state, min, max, width);
}

//_____ move_elements_to_stack_b() _____
//	Each "chunk" is simply a chunk (a grouping of elements)
//
//	moved	=	# of elements pulled from stack 'a' to stack 'b'
//				in a given round (using this function)
//	rev		=	# of rotations ("revolutions") since last time an element
//				was pushed from stack 'a' to stack 'b'
//
//				The loop also guards against spinning indefinitely:
// 				if rev > size, the loop exits.
//
//	r		= 	the rank of a given element being examined in stack 'a'
//
//	The idea of the function is to push elements from stack 'a' to stack 'b'
//	in ascending chunk order.
//
//	The function does not perfectly sort the elements.
//
//	Rather, it's more like a pre-sort -- which decreases future operations.
//
//	Function examines each element in stack `a`:
//		If the rank of the element fits within the current
//		chunk's [min, max) range, push that element to stack 'b'.
//
//		Otherwise, rotate to next element in stack 'a' via op_ra().
//
//		Repeat this process until all relevant elements in the current chunk
//		have been moved to stack 'b'.
//
//		The more chunks that have been sorted, the fewer elements
//		in stack 'a' to process
// 		so the sorting process moves more quickly over time.
//

static void	move_elements_to_stack_b(t_prog_state *state, int min,
				int max, int width)
{
	int	moved;
	int	rev;
	int	r;

	moved = 0;
	rev = 0;
	while (moved < width && state->a->size > 0 && rev <= state->a->size)
	{
		r = state->a->top->rank;
		if (r >= min && r < max)
		{
			op_pb(state);
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

/*	_____ push_elements_back_to_stack_a()_____
//	Function searches for the position of the element with the highest value
// and rotates the stack so that this element is at the top of stack 'b' and
// then pushes that element over to stack 'a'
//
// We use smart_rotate() to minimize the number of rotations required
// by first looking at whether it's faster to rotate in one direction or
// the other.
*/
void	push_elements_back_to_stack_a(t_prog_state *state)
{
	while (state->b->size > 0)
	{
		smart_rotate(state, state->b, find_pos_max(state->b));
		op_pa(state);
	}
}
