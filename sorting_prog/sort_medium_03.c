/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:38:08 by diamo             #+#    #+#             */
/*   Updated: 2026/07/08 17:56:03 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	pull_chuncks_to_b(t_prog_state *state, int chunck_min_value,
				int chunck_max_value, int chunck_width);
static void	scan_one_chunck(t_prog_state *state, int band, int chunk_size,
				int n);

/*
	...
*/
void	distribute_to_stack_b(t_prog_state *state, int chunk_size,
			int num_chunks, int n)
{
	int	i;

	i = 0;
	while (i < num_chunks)
	{
		scan_one_chunck(state, i, chunk_size, n);
		i++;
	}
}

/*
	
*/
static void	scan_one_chunck(t_prog_state *state, int band, int chunk_size,
				int n)
{
	int	chunck_min_value;
	int	chunck_max_value;
	int	chunck_width;

	chunck_min_value = band * chunk_size;
	chunck_max_value = chunck_min_value + chunk_size;
	if (chunck_max_value > n)
		chunck_max_value = n;
	chunck_width = chunck_max_value - chunck_min_value;
	pull_chuncks_to_b(state, chunck_min_value, chunck_max_value, chunck_width);
}

/*

*/
static void	pull_chuncks_to_b(t_prog_state *state, int chunck_min_value,
				int chunck_max_value, int chunck_width)
{
	int	pulled_nodes_amount;
	int	rev;
	int	a_top_node_val;
	int	chunck_mid_value;

	pulled_nodes_amount = 0;
	rev = 0;
	chunck_mid_value = (chunck_min_value + chunck_max_value) / 2;
	while (pulled_nodes_amount < chunck_width && state->a->size > 0
		&& rev <= state->a->size)
	{
		a_top_node_val = state->a->top->rank;
		if (a_top_node_val >= chunck_min_value && a_top_node_val < chunck_max_value)
		{
			op_pb(state);
			if (a_top_node_val <= chunck_mid_value && state->b->size > 1)
				op_rb(state);
			pulled_nodes_amount++;
			rev = 0;
		}
		else
		{
			op_ra(state);
			rev++;
		}
	}
}


/*

*/
void	restore_to_stack_a(t_prog_state *state)
{
	while (state->b->size > 0)
	{
		smart_rotate(state, state->b, find_pos_max(state->b));
		op_pa(state);
	}
}
