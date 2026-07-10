/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strategy_dispatcher.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:18:35 by diamo             #+#    #+#             */
/*   Updated: 2026/07/10 12:09:42 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_asc(t_stack *s);

void	dispatch_algo_strategy(t_prog_state *state)
{
	if (!state || !state->a)
		return ;
	if (is_sorted_asc(state->a))
		return ;
	if (state->strat_req == SIMPLE)
	{
		state->strat_used = SIMPLE;
		sort_simple(state);
	}
	else if (state->strat_req == MEDIUM)
	{
		state->strat_used = MEDIUM;
		sort_medium(state);
	}
	else if (state->strat_req == COMPLEX)
	{
		state->strat_used = COMPLEX;
		sort_complex(state);
	}
	else
	{
		state->strat_used = ADAPTIVE;
		sort_adaptive(state);
	}
}

/*	_____ is_sorted_asc() _____
	Checks if a given stack (e.g. 'a') is already
	sorted in ascending order.
*/

int	is_sorted_asc(t_stack *s)
{
	t_node	*node;
	int		i;

	if (!s || s->size <= 1)
		return (1);
	node = s->top;
	i = 0;
	while (i < s->size - 1)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}
