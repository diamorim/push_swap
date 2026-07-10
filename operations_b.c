/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:31:48 by diamo             #+#    #+#             */
/*   Updated: 2026/07/10 12:36:13 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sb(t_prog_state *state)
{
	if (!state || !state->b || state->b->size < 2)
		return ;
	swap(state->b);
	record_ops(state, OP_SB);
	print_op("sb\n");
}

void	op_pb(t_prog_state *state)
{
	if (!state || !state->a || state->a->size == 0)
		return ;
	push(state->a, state->b);
	record_ops(state, OP_PB);
	print_op("pb\n");
}

void	op_rb(t_prog_state *state)
{
	if (!state || !state->b || state->b->size < 2)
		return ;
	rotate(state->b);
	record_ops(state, OP_RB);
	print_op("rb\n");
}

void	op_rrb(t_prog_state *state)
{
	if (!state || !state->b || state->b->size < 2)
		return ;
	reverse_rotate(state->b);
	record_ops(state, OP_RRB);
	print_op("rrb\n");
}
