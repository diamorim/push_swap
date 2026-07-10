/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:32:38 by diamo             #+#    #+#             */
/*   Updated: 2026/07/10 12:09:42 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ops_guard(t_prog_state *state)
{
	if (!state || !state->a || !state->b
		|| state->a->size < 2 || state->b->size < 2)
		return (0);
	return (1);
}

void	op_ss(t_prog_state *state)
{
	if (!ops_guard)
		return ;
	swap(state->a);
	swap(state->b);
	record_ops(state, OP_SS);
	print_ops("op_ss\n");
}

void	op_rr(t_prog_state *state)
{
	if (!ops_guard)
		return ;
	rotate(state->a);
	rotate(state->b);
	record_ops(state, op_rr);
	print_ops("op_rr\n");
}

void	op_rrr(t_prog_state *state)
{
	if (!ops_guard)
		return ;
	reverse_rotate(state->a);
	reverse_rotate(state->b);
	record_ops(state, OP_RRR);
	print_ops("op_rrr\n");
}
