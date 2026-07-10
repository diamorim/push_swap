/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:32:38 by diamo             #+#    #+#             */
/*   Updated: 2026/07/10 14:04:04 by diamo            ###   ########.fr       */
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
	if (!ops_guard(state))
		return ;
	swap(state->a);
	swap(state->b);
	record_ops(state, OP_SS);
	print_op("ss\n");
}

void	op_rr(t_prog_state *state)
{
	if (!ops_guard(state))
		return ;
	rotate(state->a);
	rotate(state->b);
	record_ops(state, OP_RR);
	print_op("rr\n");
}

void	op_rrr(t_prog_state *state)
{
	if (!ops_guard(state))
		return ;
	reverse_rotate(state->a);
	reverse_rotate(state->b);
	record_ops(state, OP_RRR);
	print_op("rrr\n");
}
