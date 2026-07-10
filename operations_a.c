/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:26:05 by diamo             #+#    #+#             */
/*   Updated: 2026/07/10 12:09:42 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_prog_state *state)
{
	if (!state || !state->a || state->a->size < 2)
		return ;
	swap(state->a);
	record_ops(state, OP_SA);
	print_ops("sa\n");
}

void	op_pa(t_prog_state *state)
{
	if (!state || !state->b || state->b->size == 0)
		return ;
	push(state->b, state->a);
	record_ops(state, OP_PA);
	print_ops("pa\n");
}

void	op_ra(t_prog_state *state)
{
	if (!state || !state->a || state->a->size < 2)
		return ;
	rotate(state->a);
	record_ops(state, OP_RA);
	print_ops("ra\n");
}

void	op_rra(t_prog_state *state)
{
	if (!state || !state->a || state->a->size < 2)
		return ;
	reverse_rotate(state->a);
	record_ops(state, OP_RRA);
	print_ops("rra\n");
}
