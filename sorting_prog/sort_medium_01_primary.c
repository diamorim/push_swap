/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_01_primary.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:03:16 by diamo             #+#    #+#             */
/*   Updated: 2026/07/08 14:19:55 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		compute_chunk_size(int n);

void	distribute_to_stack_b(t_prog_state *state, int chunk_size,
			int num_chunks, int n);

/*
	The idea of this function is first split the stack
	into evenly sized chunks -- we do this to minimize the
	number of operations.

	We determind the # of chunks based on the approximate
	square root of the # of elements in the stack.
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
	restore_to_stack_a(state);
}
