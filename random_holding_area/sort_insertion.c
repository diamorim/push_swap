/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:29:28 by diamo             #+#    #+#             */
/*   Updated: 2026/07/10 12:09:42 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_insertion_rank(t_stack *s, int value);

//	____ sort_insertion() ____
//
// We start by pushing everything but the first
// three elements into stack b.
//
// Next, we sort the first 3 elements.
//
// Stack B now olds all of the remaining elements.
//
// Step-by-step, we remove an element from
// B until it is completely empty.
//
//
//

void	sort_insertion(t_prog_state *state)
{
	int	rank;
	int	min_pos;
	int	target;

	if (!state || !state->a || state->a->size <= 1)
		return ;
	if (handle_small_sort(state))
		return ;
	while (state->a->size > 3)
		op_pb(state);
	sort_3(state);
	while (state->b->size > 0)
	{
		rank = get_insertion_rank(state->a, state->b->top->value);
		min_pos = find_pos_min(state->a);
		target = (min_pos + rank) % state->a->size;
		smart_rotate(state, state->a, target);
		op_pa(state);
	}
	smart_rotate(state, state->a, find_pos_min(state->a));
}

// ____ get_insertion_rank ____
//	Counts how many elements in a given stack
// are smaller than a given `value`.
//
// The idea is to calculate the rank of the value
// inside a given stack -- how many elements would
// come before it.
//
// This is used to compute the exact rotation target
// for insertion.
//

static int	get_insertion_rank(t_stack *s, int value)
{
	t_node	*node;
	int		i;
	int		count;

	if (!s || s->size == 0)
		return (0);
	node = s->top;
	i = 0;
	count = 0;
	while (i < s->size)
	{
		if (node->value < value)
			count++;
		node = node->next;
		i++;
	}
	return (count);
}
