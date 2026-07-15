/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:17:43 by diamo             #+#    #+#             */
/*   Updated: 2026/07/15 18:25:58 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_prog_state *state)
{
	if (handle_small_sort(state))
		return ;
	extract_move_lowest_to_stack_b(state);
	sort_3(state);
	while (state->b->size > 0)
		op_pa(state);
}
