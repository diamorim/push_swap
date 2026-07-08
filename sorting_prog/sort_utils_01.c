/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:18:48 by diamo             #+#    #+#             */
/*   Updated: 2026/07/08 18:19:33 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_largest_to_bottom(t_prog_state *state, int val_top,
				int val_middle, int val_bottom);
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
	are only 3 elements to be sorted (6 possible unsorted
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
	rotate_largest_to_bottom(state, val_top, val_middle, val_bottom);
	val_top = state->a->top->value;
	val_middle = state->a->top->next->value;
	if (val_top > val_middle)
		op_sa(state);
}

static void	rotate_largest_to_bottom(t_prog_state *state, int val_top,
	int val_middle, int val_bottom)
{
	if (val_top > val_middle && val_top > val_bottom)
		op_ra(state);
	else if (val_middle > val_top && val_middle > val_bottom)
		op_rra(state);
}
