/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:26:05 by diamo             #+#    #+#             */
/*   Updated: 2026/06/29 13:47:47 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void op_sa(t_prog_state *state) {
	if (!state || !state->a || state->a->size < 2)
		return;
	  swap(state->a);
	record_ops(state, OP_SA);
	ft_putstr_fd("sa\n", 1);
}

void op_pa(t_prog_state *state) {
	if (!state || !state->b)
		return;
	push(state->b, state->a);
	record_ops(state, OP_PA);
	ft_putstr_fd("pa\n", 1);
}

void op_ra(t_prog_state *state)
{
	if (!state || state->a)
		return;
	rotate(state->a);
	record_ops(state, OP_RA);
	ft_putstr_fd("ra\n", 1);
}

void op_rra(t_prog_state *state)
{
	if (!state || !state->a)
		return;
	reverse_rotate(state->a);
	record_ops(state, OP_RRA);
	ft_putstr_fd("rra\n", 1);
}
