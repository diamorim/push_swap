/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_01_primary.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:10:57 by diamo             #+#    #+#             */
/*   Updated: 2026/07/10 12:09:42 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		compute_chunk_size(int n);

void	distribute_to_stack_b(t_prog_state *state, int chunk_size,
			int num_chunks, int n);

/*	_____ sort_medium()_____
//	For <=5 elements, function calls handle_small_sort()
//	due to its higher efficiency.
//
//	For more than 5 elements, sort_medium() proceeds to
//	split the stack into ˜evenly sized chunks. We do this
//	to minimize the number of total operations used to sort.
//
//	We determine the chunk size based on the approximate
//	square root of the # of elements in the stack (rounding down).
//
//	sort_medium() will go through every element in stack `a` at
//	least once and push 1 chunk worth of elements into stack 'b'
// 	on each pass and on successive journeys examine fewer &
//	fewer elements.
//
//	chunk_size is calculated via compute_chunk_size(), and num_chunks
//	is derived from it using a ceiling-division formula.
*/
void	sort_medium(t_prog_state *state)
{
	int	chunk_size;
	int	num_chunks;
	int	n;

	if (!state || !state->a)
		return ;
	if (handle_small_sort(state))
		return ;
	n = state->a->size;
	rank(state);
	chunk_size = compute_chunk_size(n);
	num_chunks = (n + chunk_size - 1) / chunk_size;
	distribute_to_stack_b(state, chunk_size, num_chunks, n);
	push_elements_back_to_stack_a(state);
}
