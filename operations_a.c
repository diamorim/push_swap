/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:26:05 by diamo             #+#    #+#             */
/*   Updated: 2026/06/23 15:52:12 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_sa(t_stack *stack_a, t_prog_state *prog_state)
{
	t_node *top_node;
	t_node *new_top;

	if (!stack_a || stack_a->size < 2)
		return ;
	top_node = stack_a->top;
	new_top = top_node->next;
	if (new_top->next)
		new_top->next = top_node;
	top_node->next = new_top->next;
	top_node->prev = new_top->prev;
	new_top->next = top_node;
	new_top->prev = NULL;
	prog_state->ops_count_per_type[OP_SA]++;
	prog_state->ops_count_total++;
}

void op_pa(t_stack *stack_a, t_stack *stack_b, t_prog_state *prog_state)
{
	t_node *new_btop;
	t_node *top;

	if (!stack_b || !prog_state)
		return;
	if (!stack_b->top)
		return ;
	top = stack_b->top;
	if (top->next)
	{
		new_btop = top->next;
		new_btop->prev = NULL;
		stack_add_front(stack_a, top);
		stack_b->top = new_btop;
	}
	else
	{
		stack_add_front(stack_a->top, stack_b->top);
		stack_b->top = NULL;
	}
	stack_b->size--;
	prog_state->ops_count_per_type[OP_PA]++;
	prog_state->ops_count_total++;
}
void ra_op(t_stack *stack_a, t_prog_state *state)
{
	t_node *last_node;
	t_node *new_top;
	
	if (!stack_a || !state)
		return ;
	last_node = stack_last_node(stack_a);
	new_top = stack_a->top->prev;
	stack_a->top->prev = NULL;
	stack_a->top->next = last_node;
	stack_a->top = new_top;
	new_top->next = NULL;
	state->ops_count_per_type[OP_RA]++;
	state->ops_count_total++;
}
void rra_op(t_stack *stack_a, t_prog_state *prog_state)
{
	t_node *last_node;
	t_node *new_top;

	if (!stack_a || !prog_state)
		return ;
	new_top = stack_last_node(stack_a);
	new_top->next->prev = NULL;
	stack_a->top = new_top;
	new_top->prev = stack_a->top;
	new_top->next = NULL;
	stack_a->top = new_top;
	prog_state->ops_count_per_type[OP_RRA]++;
	prog_state->ops_count_total++;
}

