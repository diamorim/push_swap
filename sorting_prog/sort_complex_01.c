/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:02:17 by diamo             #+#    #+#             */
/*   Updated: 2026/07/08 18:27:34 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		rank(t_prog_state *state);
int			count_bits(int n);
void		push_all_a(t_prog_state *state);
static void	iterate_bits(t_prog_state *state, int bit, int stack_size);

void	sort_complex(t_prog_state *state)
{
	int	bit;
	int	biggest_bit;
	int	stack_size;

	if (state->a->size <= 3)
	{
		handle_small_sort(state);
		return ;
	}
	stack_size = state->a->size;
	rank(state);
	bit = 0;
	biggest_bit = count_bits(stack_size - 1);
	while (bit < biggest_bit)
	{
		iterate_bits(state, bit, stack_size);
		push_all_a(state);
		bit++;
	}
}

int	count_bits(int n)
{
	int	bits;

	bits = 0;
	while (n > 0)
	{
		n = n >> 1;
		bits++;
	}
	return (bits);
}

static void	iterate_bits(t_prog_state *state, int bit, int stack_size)
{
	int	i;

	i = 0;
	while (i < stack_size)
	{
		if ((state->a->top->rank >> bit) & 1)
			op_ra(state);
		else
			op_pb(state);
		i++;
	}
}

void	push_all_a(t_prog_state *state)
{
	int	i;
	int	target;

	target = state->b->size;
	i = 0;
	while (i < target)
	{
		op_pa(state);
		i++;
	}
}

//4, 3, 2, 1
//0100  0011   0010    0001
//stack a: 3, 1
//stack b: 4, 2
//stack a: 2, 4, 3, 1