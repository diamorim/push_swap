/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:26:05 by diamo             #+#    #+#             */
/*   Updated: 2026/06/25 17:27:43 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_sa(t_prog_state *state)
{
	t_stack *stack_a;
	t_node *top_node;
	t_node *new_top;

	if (!state->a || state->a->size < 2)
		return ;
	stack_a = state->a;
	top_node = stack_a->top;
	new_top = top_node->next;
	if (new_top->next)
	{
		top_node->next = new_top->next;
		new_top->next = top_node;
		new_top->prev = top_node->prev;
		top_node->prev = new_top;
	}
	else
	{
		change_next_prev(top_node, new_top, new_top);
		change_next_prev(new_top, top_node, top_node);
	}
	stack_a->top = new_top;
	state->ops_count_per_type[OP_SA]++;
	state->ops_count_total++;
	ft_putstr_fd("sa\n", 1);
}

void op_pa(t_prog_state *state)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_node *new_btop;
	t_node *top;

	if (!state->a || !state)
		return;
	stack_a = state->a;
	if (!state->b->top)
		return ;
	stack_b = state->b;
	top = stack_b->top;
	if (top->next)
	{
		new_btop = top->next;
		new_btop->prev = top->prev;
		stack_add_front(stack_a, top);
		stack_b->top = new_btop;
	}
	else
	{
		stack_add_front(stack_a, stack_b->top);
		stack_b->top = NULL;
	}
	stack_b->size--;
	state->ops_count_per_type[OP_PA]++;
	state->ops_count_total++;
	ft_putstr_fd("pa\n", 1);
}
void op_ra(t_prog_state *state)
{
	t_stack *stack_a;
	if (!state->a || !state)
		return ;
	stack_a = state->a;
	stack_a->top = stack_a->top->next;
	state->ops_count_per_type[OP_RA]++;
	state->ops_count_total++;
	ft_putstr_fd("ra\n", 1);
}
void op_rra(t_prog_state *state)
{
	t_stack *stack_a;
	if (!state->a || !state)
		return ;
	stack_a = state->a;
	stack_a->top = stack_a->top->prev;
	state->ops_count_per_type[OP_RRA]++;
	state->ops_count_total++;
	ft_putstr_fd("rra\n", 1);
}

